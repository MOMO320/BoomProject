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
	int32 GetMoney() const;
	EWeaponMode GetWeaponeMode() const;

	float GetPlayerExpRatio() const;

	bool PlayerAddExp(int32 ComeExp);
	
	void InitPlayerData();
	void SavePlayerData();

	FOnPlayerStateChangedDelegate OnPlayerStateChanged;

	void AddPlayerMoney(int32 AddMoney);

private:
	float ExpCalculator(float NextExp, float CurrentExp) const;

public:
	FString SaveSlotName;

protected:
	UPROPERTY(Transient)
		int32 PlayerLevel;

	UPROPERTY(Transient)
		int32 PlayerExp;

	UPROPERTY(Transient)
		int32 Money;

	UPROPERTY()
		EWeaponMode WeaponMode;

private:
	void SetPlayerLevel(int32 newCharacterLevel);
	struct FPlayerCharacterData* PlayerStatData;

};
