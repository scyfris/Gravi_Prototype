// Fill out your copyright notice in the Description page of Project Settings.

#include "GraviPrototype.h"
#include "TestCPPClass.h"


// Sets default values
ATestCPPClass::ATestCPPClass()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestCPPClass::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestCPPClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

