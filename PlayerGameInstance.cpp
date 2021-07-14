// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerGameInstance.h"

UPlayerGameInstance::UPlayerGameInstance()
{
	FString CharacterDataPath = TEXT("/Game/DataTable/PlayerCharacterData.PlayerCharacterData");

	static ConstructorHelpers::FObjectFinder<UDataTable> DT_CHARACTER(*CharacterDataPath);

	if (DT_CHARACTER.Succeeded())
		PlayerCharacterTable = DT_CHARACTER.Object;

	MYCHECK(PlayerCharacterTable->GetRowMap().Num() > 0);
}

FPlayerCharacterData* UPlayerGameInstance::GetPlayerCharacterData(int32 Level)
{
	return PlayerCharacterTable->FindRow<FPlayerCharacterData>(*FString::FromInt(Level), TEXT(""));
}

FWeaponData* UPlayerGameInstance::GetWeaponData(EWeaponMode WeaponMode, int32 Level)
{
	return nullptr;
}
