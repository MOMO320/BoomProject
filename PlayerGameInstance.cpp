// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerGameInstance.h"

UPlayerGameInstance::UPlayerGameInstance()
{
	PlayerCharacterTable = DataObjectPath(TEXT("/Game/DataTable/PlayerCharacterData.PlayerCharacterData"));
	SwordDataTable = DataObjectPath(TEXT("/Game/DataTable/SwordData.SwordData"));
	GunDataTable = DataObjectPath(TEXT("/Game/DataTable/GunData.GunData"));
}

FPlayerCharacterData* UPlayerGameInstance::GetPlayerCharacterData(int32 Level)
{
	return PlayerCharacterTable->FindRow<FPlayerCharacterData>(*FString::FromInt(Level), TEXT(""));
}

FWeaponData* UPlayerGameInstance::GetSwordData(int32 Level)
{
	return ;
}

FWeaponData* UPlayerGameInstance::GetGunData(int32 Level)
{
	return nullptr;
}

UDataTable* UPlayerGameInstance::DataObjectPath(FString DataPath)
{
	ConstructorHelpers::FObjectFinder<UDataTable> DT(*DataPath);

	if (DT.Succeeded())
	{
		MYCHECK(DT.Object->GetRowMap().Num() > 0);
		return DT.Object;
	}

	MYLOG(Warning, TEXT("%s No Data"), DataPath);

	return nullptr;
}
