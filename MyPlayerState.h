// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BoomProject.h"
#include "GameFramework/PlayerState.h"
#include "MyPlayerState.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnPlayerStateChangedDelegate);

/**
 * 
 */
UCLASS()
class BOOMPROJECT_API AMyPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	AMyPlayerState();

	int32 GetPlayerLevel() const;
	int32 GetSwordExp() const;
	int32 GetGunExp() const;
	EWeaponMode GetWeaponeMode() const;

	float GetPlayerExpRatio() const;
	float GetSwordExpRatio() const;
	float GetGunExpRatio() const;

	bool AddExp(int32 IncomeExp);

	void InitPlayerData();
	void SavePlayerData();

	FOnPlayerStateChangedDelegate OnPlayerStateChanged;

	void AddPlayerMoney();

public:
	FString SaveSlotName;

protected:
	UPROPERTY(Transient)
		int32 PlayerLevel;

	UPROPERTY(Transient)
		int32 Exp;

	UPROPERTY(Transient)
		int32 Money;

private:
	void SetPlayerLevel(int32 newCharacterLevel);

};
