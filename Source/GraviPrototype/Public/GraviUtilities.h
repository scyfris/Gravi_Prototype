// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "GraviUtilities.generated.h"

/**
 * 
 */
UCLASS()
class GRAVIPROTOTYPE_API UGraviUtilities : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintPure, Category="GraviUtilities")
	static FVector2D GetPerpDirectionCounterClockwise2D(FVector2D inVec);

	UFUNCTION(BlueprintPure, Category="GraviUtilities")
	static FVector GetPerpDirectionCounterClockwise3D(FVector inVec);

	UFUNCTION(BlueprintPure, Category="GraviUtilities")
	static FVector2D Get2DVector(FVector inVec);

	UFUNCTION(BlueprintPure, Category="GraviUtilities")
	static FVector Get3DVector(FVector2D inVec, float yVal = 0.0f);

	// Based on the vector, will return 0, 1, 2, or 3.  0 will be returned if vector is pointing down,
	// 1 if right, 2 if up, 3 if left.  meant to be used when selecting the corners of a box.
	// Vector does not need to be normalized
	UFUNCTION(BlueprintPure, Category="GraviUtilities")
	static int GetQuadrantFirstIndex(FVector2D inDir);

	UFUNCTION(BlueprintPure, Category="GraviUtilities")
	static TArray<FVector> Convert2DVecArrayTo3D(const TArray<FVector2D> & inVecArray, float yPos = 0.0f);

	UFUNCTION(BlueprintPure, Category="GraviUtilities")
	// Gets the amount of inputVector in the direction of DirectionVector.  this involves normalizing directionVector
	// and the performing a dot product.
	static void GetVectorInDirection(const FVector2D &inputVector, const FVector2D directionVector, FVector2D & outVec);
};
