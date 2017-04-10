// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "TestCPPClass.generated.h"

UCLASS()
class GRAVIPROTOTYPE_API ATestCPPClass : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, Category="DAMAGE")
	int TotalDamage;

public:	
	// Sets default values for this actor's properties
	ATestCPPClass();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
