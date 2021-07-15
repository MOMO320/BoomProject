// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "WeaponState.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnWeaponeStateChangedDelegate);

/**
 * 
 */
UCLASS()
class BOOMPROJECT_API AWeaponState : public APlayerState
{
	GENERATED_BODY()

public:
	AWeaponState();

	int32 GetWeaponLevel() const;
	float GetSwordExpRatio() const;
	float GetGunExpRatio() const;

	void InitWeaponsData();
	void SaveWeaponsData();

	FOnWeaponeStateChangedDelegate OnWeaponStateChanged;

private:
	float ExpCalculator(float NextExp, float CurrentExp) const;

private:
	struct FWeaponData* SwordStatData;
	struct FWeaponData* GunStatData;
};
