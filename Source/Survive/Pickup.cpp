// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup.h"
#include <Runtime/Engine/Classes/Components/StaticMeshComponent.h>

// Sets default values
APickup::APickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	bIsActive = true;

	//Initiate Static Mesh
	PickUpMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickUpMesh"));
	RootComponent = PickUpMesh;

}

// Called when the game starts or when spawned
void APickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool APickup::isActive() {
	return bIsActive;
}

void APickup::setActive(bool newState) {
	bIsActive = newState;
}

void APickup::isCollected_Implementation() {
	FString DebugString = GetName();
	UE_LOG(LogClass, Log, TEXT("You have collected %s"), *DebugString);
	Destroy();
}

