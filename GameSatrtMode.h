// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameSatrtMode.generated.h"

/**
 * 
 */
UCLASS()
class BOOMPROJECT_API AGameSatrtMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGameSatrtMode();
	
	virtual void PostInitializeComponents() override;
};
