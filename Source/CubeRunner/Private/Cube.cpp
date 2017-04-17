// Fill out your copyright notice in the Description page of Project Settings.

#include "CubeRunner.h"
#include "Cube.h"


ACube::ACube(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	CubeMesh = PCIP.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("CubeMesh"));
	Capsule = PCIP.CreateDefaultSubobject<UCapsuleComponent>(this, TEXT("Capsule"));
	RootComponent = Capsule;
	CubeMesh->AttachParent = RootComponent;
}


