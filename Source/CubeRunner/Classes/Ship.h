// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "Ship.generated.h"

/**
 * 
 */
UCLASS()
class CUBERUNNER_API AShip : public ACharacter
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Mesh)
	TSubobjectPtr<UStaticMeshComponent> Mesh3P;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	TSubobjectPtr<UCameraComponent> ShipCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Spawning)
	TSubobjectPtr<UBoxComponent> SpawningVolume;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Spawning)
	TSubobjectPtr<UBoxComponent> DespawningVolume;


	UPROPERTY(EditAnywhere, Category = Spawning)
	TSubclassOf<class ACube> BoxToSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawning)
	float SpawnDelayRangeHigh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawning)
	float SpawnDelayRangeLow;

	UFUNCTION(BlueprintPure, Category = Spawning)
	FVector GetRandomPointInVolume();
private:
	float GetRandomSpawnDelay();

	float SpawnDelay;

	void SpawnBox();

	float SpawnTime;
protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	virtual void Tick(float DeltaSeconds) override;
	void MoveRight(float Value);
	void MoveForward(float Value);
};
