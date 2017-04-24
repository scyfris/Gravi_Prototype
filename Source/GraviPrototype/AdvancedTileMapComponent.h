// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PaperTileMapComponent.h"
#include "AdvancedTileMapComponent.generated.h"

/**
 * A utility TileMap component with various functionality not provided by the public
 * UPaperTileMapComponent interface.
 */
UCLASS()
class GRAVIPROTOTYPE_API UAdvancedTileMapComponent : public UPaperTileMapComponent
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintPure, Category = "GraviUtilities")
	static void GetTileCoordinatesFromLocalSpacePosition(const UPaperTileMapComponent * compRef, const FVector& Position, int32& OutTileX, int32& OutTileY);	
};
