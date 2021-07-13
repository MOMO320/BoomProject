// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BoomProject.h"
#include "GameFramework/SaveGame.h"
#include "PlayerSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class BOOMPROJECT_API UPlayerSaveGame : public USaveGame
{
	GENERATED_BODY()
	
public:
	UPlayerSaveGame();

public:

	UPROPERTY()
		FString Name;

	UPROPERTY()
		int32 Level;

	UPROPERTY()
		int32 Exp;

	UPROPERTY()
		int32 Money;

	// items , Weapone, Armor --> Later


};
