// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Cube.generated.h"

/**
 * 
 */
UCLASS()
class CUBERUNNER_API ACube : public AActor
{
	GENERATED_UCLASS_BODY()
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Mesh)
	TSubobjectPtr<UStaticMeshComponent> CubeMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = CapsuleComponent)
	TSubobjectPtr<UCapsuleComponent> Capsule;
};
