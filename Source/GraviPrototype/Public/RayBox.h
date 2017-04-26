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

struct Frar {

	int myTest;

	int dummyVal;
};
	
USTRUCT(BlueprintType)
struct FrarWrapper {
	GENERATED_USTRUCT_BODY()

	Frar * fRarPointer;	
};

/**
 * 
 */
UCLASS(Blueprintable, ClassGroup=(Gravi), editinlinenew, meta=(BlueprintSpawnableComponent) )
class GRAVIPROTOTYPE_API URayBox : public UActorComponent 
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FrarWrapper myFrarRef;

	UFUNCTION(BlueprintPure, Category="Utilities")
	static int GetFrarMyTest(const FrarWrapper & frarRef);

	UFUNCTION(BlueprintCallable, Category="Utilities")
	static void SetFrarMyTest(FrarWrapper frarRef, int testVal);

	// World centers of the box.  Needs to be set before casting
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MustSet")
	FVector2D BoxWorldCenter;

	// Extents of the box.  Needs to be set before casting.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MustSet")
	FVector2D BoxExtents;

public:

	// Initializes "myRar" with a new operator
	UFUNCTION(BlueprintCallable)
    void CreateMyRar();
	
	// Gets the box corners by looking at input vector's down direction and going counter-clockwise.
	// Index0Direction is the direction to get 0, 1 first.
	UFUNCTION(BlueprintCallable)
	void GetBoxWorldCorners(const FVector2D & index0Direction, TArray<FVector2D> & outCorners, int & outFirstIndex);

	UFUNCTION(BlueprintCallable)
	void SetBounds(FVector center, FVector extents);

	UFUNCTION(BlueprintCallable)
		void CastRays(float inRayLengths, float inRayOffsets, int numRaysPerSide,
			TArray<FRayBundle> & outRays, bool drawDebugLines = false, float yPos = 0.0f, float boundryScaleFraction = 0.7f);
	
};
