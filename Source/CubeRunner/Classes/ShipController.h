// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "ShipController.generated.h"

/**
 * Used to be CUBERUNNER_API
 */
UCLASS()
class CUBERUNNER_API AShipController : public APlayerController
{
	GENERATED_UCLASS_BODY()

public:

	//Activates in-game menu
	void OnToggleInGameMenu();
	

protected:
	//Sets up input components for the controller
	virtual void SetupInputComponent() override;
	

	//Ship in game menu
	//TSharedPtr<class FShipIngameMenu> ShipIngameMenu;

	
	
	
};
