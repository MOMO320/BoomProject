
// Fill out your copyright notice in the Description page of Project Settings.


#include "GameSatrtMode.h"
#include "GameStartController.h"

AGameSatrtMode::AGameSatrtMode()
{
	PlayerControllerClass = AGameStartController::StaticClass();
}

void AGameSatrtMode::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

