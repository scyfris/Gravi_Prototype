// Fill out your copyright notice in the Description page of Project Settings.

#include "GraviPrototype.h"
#include "GraviUtilities.h"

#include <limits>

FVector2D UGraviUtilities::GetPerpDirectionCounterClockwise2D(FVector2D inVec)
{
	FVector2D retVec;
	retVec.X = inVec.Y * -1.0f;
	retVec.Y = inVec.X;

	return retVec;
}

FVector UGraviUtilities::GetPerpDirectionCounterClockwise3D(FVector inVec)
{
	float yVal = inVec.Y;

	return Get3DVector(GetPerpDirectionCounterClockwise2D(Get2DVector(inVec)), yVal);
}

FVector2D UGraviUtilities::Get2DVector(FVector inVec)
{
	return FVector2D(inVec.X, inVec.Z);
}

FVector UGraviUtilities::Get3DVector(FVector2D inVec, float yVal)
{
	return FVector(inVec.X, yVal, inVec.Y);
}

int UGraviUtilities::GetQuadrantFirstIndex(FVector2D inDir)
{
	FVector2D dirs[4] =
	{
		FVector2D(0, -1), // down
		FVector2D(1, 0), // right
		FVector2D(0, 1), // up
		FVector2D(-1, 0) // left
	};

	float currMax = 0.0f;
	int maxIdx = 0;

	for (int i = 0; i < 4; ++i) {
		float dotProd = FVector2D::DotProduct(inDir, dirs[i]);// FVector2D.DotProduct(inDir, dirs[i]);

		if (dotProd > currMax) {
			maxIdx = i;
			currMax = dotProd;
		}
	}

	return maxIdx;
}