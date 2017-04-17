// Fill out your copyright notice in the Description page of Project Settings.

#include "CubeRunner.h"
#include "ShipController.h"


AShipController::AShipController(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	


}

void AShipController::SetupInputComponent() 
{
	Super::SetupInputComponent();

	InputComponent->BindAction("InGameMenu", IE_Pressed, this, &AShipController::OnToggleInGameMenu);
}

void AShipController::OnToggleInGameMenu()
{
	/*
	if (ShipIngameMenu.IsValid())
	{
		
		ShipIngameMenu->ToggleGameMenu();
	}*/
}


