// Fill out your copyright notice in the Description page of Project Settings.

#include "CubeRunner.h"
#include "CubeRunnerGameMode.h"
#include "ShipHUD.h"
#include "ShipController.h"

ACubeRunnerGameMode::ACubeRunnerGameMode(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnOb(TEXT("/Game/Ship/BP_Ship"));
	DefaultPawnClass = PlayerPawnOb.Class;

	HUDClass = AShipHUD::StaticClass();
	PlayerControllerClass = AShipController::StaticClass();


}


