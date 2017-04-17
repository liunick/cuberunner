// Fill out your copyright notice in the Description page of Project Settings.

#include "CubeRunner.h"
#include "Ship.h"
#include "Cube.h"

AShip::AShip(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	Mesh3P = PCIP.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("ShipMesh"));
	ShipCameraComponent = PCIP.CreateDefaultSubobject<UCameraComponent>(this, TEXT("ShipCameraComponent"));
	SpawningVolume = PCIP.CreateDefaultSubobject<UBoxComponent>(this, TEXT("SpawningComponent"));
	DespawningVolume = PCIP.CreateDefaultSubobject<UBoxComponent>(this, TEXT("DespawningComponent"));



	Mesh3P->AttachParent = CapsuleComponent;
	ShipCameraComponent->AttachParent = CapsuleComponent;
	SpawningVolume->AttachParent = Mesh3P;
	DespawningVolume->AttachParent = Mesh3P;

	SpawnDelayRangeLow = 0.3f;
	SpawnDelayRangeHigh = 0.6f;
	SpawnDelay = GetRandomSpawnDelay();

	
	PrimaryActorTick.bCanEverTick = true;

}
void AShip::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	check(InputComponent);
	InputComponent->BindAxis("MoveRight", this, &AShip::MoveRight);
	InputComponent->BindAxis("MoveForward", this, &AShip::MoveForward);
}

void AShip::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorRightVector(), Value);
	}
}

void AShip::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void AShip::Tick(float DeltaSeconds)
{
	SpawnTime += DeltaSeconds;
	bool bShouldSpawn = (SpawnTime > SpawnDelay);

	if (bShouldSpawn)
	{
		SpawnBox();

		SpawnTime -= SpawnDelay;

		SpawnDelay = GetRandomSpawnDelay();
	}
}


void AShip::SpawnBox()
{
	if (BoxToSpawn != NULL)
	{
		UWorld* const World = GetWorld();
		if (World)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = Instigator;

			FVector SpawnLocation = GetRandomPointInVolume();

			FRotator SpawnRotation;
			SpawnRotation.Yaw = 0.f;
			SpawnRotation.Pitch = 0.f;
			SpawnRotation.Roll = 0.f;

			ACube* const SpawnedPickup = World->SpawnActor<ACube>(BoxToSpawn, SpawnLocation, SpawnRotation, SpawnParams);
		}
	}
}

float AShip::GetRandomSpawnDelay()
{
	return FMath::FRandRange(SpawnDelayRangeLow, SpawnDelayRangeHigh);
}

FVector AShip::GetRandomPointInVolume()
{

	

	float fXPos = FMath::FRandRange(0, SpawningVolume->GetScaledBoxExtent().X);
	float fYPos = FMath::FRandRange(0, SpawningVolume->GetScaledBoxExtent().Y);
	float fZPos = FMath::FRandRange(0, SpawningVolume->GetScaledBoxExtent().Z);

	return new FVector(fXPos, fYPos, fZPos); 

	

}