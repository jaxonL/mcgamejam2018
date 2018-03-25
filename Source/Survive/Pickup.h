// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Pickup.generated.h"

UCLASS()
class SURVIVE_API APickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickup();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Can the PickUp be used?
	bool bIsActive;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	// Return Mesh of Pick Up
	FORCEINLINE class UStaticMeshComponent* GetMesh() const { return PickUpMesh; }

	UFUNCTION(BlueprintPure, Category = "PickUp")
	bool isActive();

	UFUNCTION(BlueprintCallable, Category = "PickUp")
	void setActive(bool newState);

	// When PickUp is collected
	UFUNCTION(BlueprintNativeEvent)
	void isCollected();
	virtual void isCollected_Implementation();

private:
	// Static Mesh for PickUps
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PickUp", meta = (AllowPrivateAccess = "true" ))
	class UStaticMeshComponent* PickUpMesh;
	
	
};
