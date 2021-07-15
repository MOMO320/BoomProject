// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerState.h"
#include "PlayerGameInstance.h"
#include "PlayerSaveGame.h"

AMyPlayerState::AMyPlayerState()
{
	SaveSlotName = TEXT(PLAYER_NONE_NAME);
	PlayerLevel = 1;
	PlayerExp = 0;
	Money = 300;
	WeaponMode = EWeaponMode::SWORD;
}

int32 AMyPlayerState::GetPlayerLevel() const
{
	return PlayerLevel;
}

int32 AMyPlayerState::GetMoney() const
{
	return Money;
}

EWeaponMode AMyPlayerState::GetWeaponeMode() const
{
	return WeaponMode;
}

float AMyPlayerState::GetPlayerExpRatio() const
{
	return ExpCalculator((float)PlayerStatData->NextExp, (float)PlayerExp);
}

bool AMyPlayerState::PlayerAddExp(int32 ComeExp)
{
	if (PlayerStatData->NextExp == -1)
		return false;

	bool DidLevelUp = false;
	PlayerExp = PlayerExp + ComeExp;

	if (PlayerExp >= PlayerStatData->NextExp)
	{
		PlayerExp -= PlayerStatData->NextExp;
		SetPlayerLevel(PlayerLevel + 1);
		DidLevelUp = true;
	}

	OnPlayerStateChanged.Broadcast();
	SavePlayerData();
	return DidLevelUp;
}

float AMyPlayerState::ExpCalculator(float NextExp, float CurrentExp) const
{
	if (NextExp <= KINDA_SMALL_NUMBER)
		return 0.0f;

	float Result = CurrentExp / NextExp;
	MYLOG(Warning, TEXT("Ratio : %f , Current : %d , Next : %d"), Result, CurrentExp, NextExp);
	return Result;
}

void AMyPlayerState::InitPlayerData()
{
	auto PlayerSaveGame = Cast<UPlayerSaveGame>(UGameplayStatics::LoadGameFromSlot(SaveSlotName, 0));

	if (nullptr == PlayerSaveGame)
	{
		PlayerSaveGame = GetMutableDefault<UPlayerSaveGame>();
	}

	SetPlayerName(PlayerSaveGame->Name);
	SetPlayerLevel(PlayerSaveGame->Level);
	Money = 300;
	PlayerExp = PlayerSaveGame->Exp;
	SavePlayerData();
}

void AMyPlayerState::SavePlayerData()
{
	UPlayerSaveGame* NewPlayerData = NewObject<UPlayerSaveGame>();
	NewPlayerData->Name = GetPlayerName();
	NewPlayerData->Level = PlayerLevel;
	NewPlayerData->Exp = PlayerExp;
	NewPlayerData->Money = Money;
	NewPlayerData->WeaponMode = WeaponMode;

	if (!UGameplayStatics::SaveGameToSlot(NewPlayerData, SaveSlotName, 0))
	{
		MYLOG(Error, TEXT("SaveGame Error!"));
	}
}

void AMyPlayerState::AddPlayerMoney(int32 AddMoney)
{
	Money += AddMoney;
}

void AMyPlayerState::SetPlayerLevel(int32 newCharacterLevel)
{
	auto PlayerGameInstance = Cast<UPlayerGameInstance>(GetGameInstance());
	MYCHECK(nullptr != PlayerGameInstance);

	PlayerStatData = PlayerGameInstance->GetPlayerCharacterData(newCharacterLevel);
	MYCHECK(nullptr != PlayerGameInstance);

	PlayerLevel = newCharacterLevel;
}
