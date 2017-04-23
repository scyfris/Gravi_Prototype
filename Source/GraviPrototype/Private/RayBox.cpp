// Fill out your copyright notice in the Description page of Project Settings.

#include "GraviPrototype.h"
#include "GraviUtilities.h"
#include "RayBox.h"

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
