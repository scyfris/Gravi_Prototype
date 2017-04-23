// Fill out your copyright notice in the Description page of Project Settings.

#include "GraviPrototype.h"
#include "GraviUtilities.h"
#include "RayBox.h"

#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::White,text)

// Gets the box corners by looking at input vector's down direction and going counter-clockwise.
// Index0Direction is the direction to get 0, 1 first.
void URayBox::GetBoxWorldCorners(const FVector2D & index0Direction, TArray<FVector2D> & outCorners, int & outFirstIndex)
{
	// Based on the direction, set up an array of output corners
	outFirstIndex = UGraviUtilities::GetQuadrantFirstIndex(index0Direction);
	FVector2D offSets [4] = {
		-1.0f * BoxExtents,
		FVector2D(BoxExtents.X, -1.0f * BoxExtents.Y),
		BoxExtents,
		FVector2D(-1.0f * BoxExtents.X, BoxExtents.Y)
	};

	outCorners.Empty();

	for (int i = 0; i < 4; ++i) {
		int idx = (outFirstIndex + i) % 4;
		
		outCorners.Add(BoxWorldCenter + offSets[idx]);
	}
}

void URayBox::CastRays(
	float inRayLengths,
	float inRayOffsets,
	int numRaysPerSide,
	TArray<FRayBundle> & outRays,
	bool drawDebugLines,
	float yPos,
	float boundryScaleFraction,
	bool dummy)
{
	TArray<FVector2D> boxCorners;
	int firstIndex = 0;

	GetBoxWorldCorners(FVector2D(0, -1), boxCorners, firstIndex);

	outRays.Empty();

	for (int i = 0; i < 4; ++i) {
		FVector2D currentSideBounds[2] = { boxCorners[i], boxCorners[(i + 1) % 4] };
		FVector2D currentRayStartDiff = (currentSideBounds[1] - currentSideBounds[0]);
		FVector2D currentSideCenter = currentSideBounds[0] + currentRayStartDiff * 0.5f;
		FVector2D currentSideNorm = UGraviUtilities::GetPerpDirectionCounterClockwise2D(currentRayStartDiff) * -1.0f;
		currentSideNorm.Normalize();

		FRayBundle sideResults;

		for (int j = 0; j < numRaysPerSide; ++j) {
			// If (drawDebugLines)
			// DrawDebugCircle

			FVector2D startPoint = (((((float)j / (float)(numRaysPerSide - 1) * currentRayStartDiff) + currentSideBounds[0]) -
				currentSideCenter) * boundryScaleFraction) + currentSideCenter;

			FVector2D endPoint = startPoint + (currentSideNorm * inRayLengths);

			startPoint += currentSideNorm * inRayOffsets;
			FHitResult hits;
			FCollisionQueryParams collisionParams;
			collisionParams.AddIgnoredActor(GetOwner());
			//	collisionParams.TraceTag = TraceTag;

			bool wasHit = GetWorld()->LineTraceSingleByChannel(hits, UGraviUtilities::Get3DVector(startPoint),
				UGraviUtilities::Get3DVector(endPoint), ECollisionChannel::ECC_Visibility, collisionParams);

			FVector start3 = UGraviUtilities::Get3DVector(startPoint, yPos);
			FVector end3 = UGraviUtilities::Get3DVector(endPoint);
			if (drawDebugLines) {
			    DrawDebugLine(GetWorld(), start3, hits.Location, FColor(0, 255, 0), false);
			    DrawDebugLine(GetWorld(), hits.Location, end3, FColor(255, 0, 0), false);
			}
			sideResults.HitResults.Add(hits);
			sideResults.WasHit.Add(wasHit);
			if (wasHit) {
				sideResults.RayHitLengths.Add(((inRayOffsets * -1.0f + inRayLengths) * hits.Time) - (inRayOffsets * -1.0f));
			}
			else {
				sideResults.RayHitLengths.Add(0.0f);
			}
		}

		outRays.Add(sideResults);
	}

}
