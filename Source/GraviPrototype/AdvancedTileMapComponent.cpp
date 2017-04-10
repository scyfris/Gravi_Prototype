// Fill out your copyright notice in the Description page of Project Settings.

#include "GraviPrototype.h"
#include "AdvancedTileMapComponent.h"
#include "PaperTileMap.h"

void UAdvancedTileMapComponent::GetTileCoordinatesFromLocalSpacePosition(const UPaperTileMapComponent *compRef, const FVector& Position, int32& OutTileX, int32& OutTileY)
{
	return compRef->TileMap->GetTileCoordinatesFromLocalSpacePosition(Position, OutTileX, OutTileY);
}
