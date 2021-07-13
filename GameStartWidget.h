// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BoomProject.h"
#include "Blueprint/UserWidget.h"
#include "UserWidgetSystem.h"
#include "GameStartWidget.generated.h"

/**
 * 
 */
UCLASS()
class BOOMPROJECT_API UGameStartWidget : public UUserWidgetSystem
{
	GENERATED_BODY()
	
public:

protected:
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

private:
	UFUNCTION()
		void PlayerNameConfireClicked();

	UFUNCTION()
		void GameStartClicked();

		void AddWigetEvent();

		void SetPanelEnable(bool isNonePlayer);

		void CheckPlayerName();

public:
	UPROPERTY()
		class UCanvasPanel* NonePlayerPanel;

	UPROPERTY()
		class UCanvasPanel* PlayerPanel;

	UPROPERTY()
		class UTextBlock* IDErrorAramText;

	UPROPERTY()
		class UTextBlock* PlayerNameText;

	UPROPERTY()
		class UButton* GameStartButton;

	UPROPERTY()
		class UButton* PlayerNameConfireButton;

	UPROPERTY()
		class UEditableTextBox* PlayerNameInputText;



private:
	UPROPERTY()
		class UPlayerSaveGame* PlayerSaveData;

	FString PlayerName;
};
