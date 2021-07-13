// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BoomProject.h"
#include "GameFramework/PlayerController.h"
#include "GameStartController.generated.h"

/**
 * 
 */
UCLASS()
class BOOMPROJECT_API AGameStartController : public APlayerController
{
	GENERATED_BODY()

public:
	AGameStartController();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = UI)
		TSubclassOf<class UGameStartWidget> GameStartWidgetClass;

private:
	UPROPERTY()
		class UGameStartWidget* GameStartWidget;
	
	FInputModeUIOnly UIInputMode;

};
