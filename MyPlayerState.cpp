// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerState.h"


AMyPlayerState::AMyPlayerState()
{
	SaveSlotName = TEXT(PLAYER_NONE_NAME);
	PlayerLevel = 1;
	Exp = 0;
	Money = 300;
}

int32 AMyPlayerState::GetPlayerLevel() const
{
	return PlayerLevel;
}

int32 AMyPlayerState::GetSwordExp() const
{
	return int32();
}

int32 AMyPlayerState::GetGunExp() const
{
	return int32();
}

EWeaponMode AMyPlayerState::GetWeaponeMode() const
{
	return EWeaponMode();
}

float AMyPlayerState::GetPlayerExpRatio() const
{
	return 0.0f;
}

float AMyPlayerState::GetSwordExpRatio() const
{
	return 0.0f;
}

float AMyPlayerState::GetGunExpRatio() const
{
	return 0.0f;
}

bool AMyPlayerState::AddExp(int32 IncomeExp)
{
	return false;
}

void AMyPlayerState::InitPlayerData()
{
}

void AMyPlayerState::SavePlayerData()
{
}

void AMyPlayerState::AddPlayerMoney()
{
}

void AMyPlayerState::SetPlayerLevel(int32 newCharacterLevel)
{
}
