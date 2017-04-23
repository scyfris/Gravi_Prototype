// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/NoExportTypes.h"
#include <vector>

#include "RayBox.generated.h"
USTRUCT(BlueprintType)
struct FRayBundle {

	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly)
	TArray<FHitResult> HitResults;

	UPROPERTY(BlueprintReadOnly)
	TArray<float> RayHitLengths;

	UPROPERTY(BlueprintReadOnly)
	TArray<bool> WasHit;

	UPROPERTY(BlueprintReadOnly)
	int NumRaysInBundle;
};

/**
 * 
 */
UCLASS(Blueprintable, ClassGroup=(Gravi), editinlinenew, meta=(BlueprintSpawnableComponent) )
class GRAVIPROTOTYPE_API URayBox : public UActorComponent 
{
	GENERATED_BODY()
	
public:
	// World centers of the box.  Needs to be set before casting
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MustSet")
	FVector2D BoxWorldCenter;

	// Extents of the box.  Needs to be set before casting.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MustSet")
	FVector2D BoxExtents;

public:
	
	// Gets the box corners by looking at input vector's down direction and going counter-clockwise.
	// Index0Direction is the direction to get 0, 1 first.
	UFUNCTION(BlueprintCallable)
	void GetBoxWorldCorners(const FVector2D & index0Direction, TArray<FVector2D> & outCorners, int & outFirstIndex);

	UFUNCTION(BlueprintCallable)
		void CastRays(float inRayLengths, float inRayOffsets, int numRaysPerSide,
			TArray<FRayBundle> & outRays, bool drawDebugLines = false, float yPos = 0.0f, float boundryScaleFraction = 0.7f, bool dummy = false);
	
};
