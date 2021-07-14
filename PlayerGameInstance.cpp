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
	return SwordDataTable->FindRow<FWeaponData>(*FString::FromInt(Level), TEXT(""));
}

FWeaponData* UPlayerGameInstance::GetGunData(int32 Level)
{
	return GunDataTable->FindRow<FWeaponData>(*FString::FromInt(Level), TEXT(""));
}

UDataTable* UPlayerGameInstance::DataObjectPath(FString DataPath)
{
	ConstructorHelpers::FObjectFinder<UDataTable> DT(*DataPath);

	if (DT.Succeeded())
	{
		if (DT.Object->GetRowMap().Num() < 0)
			UE_LOG(LogTemp, Warning, TEXT(" === %s : NO Data === "), *DataPath);
		
		return DT.Object;
	}

	return nullptr;
}
