// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BoomProject.h"
#include "Engine/GameInstance.h"
#include "Engine/DataTable.h"
#include "Engine/StreamableManager.h"
#include "PlayerGameInstance.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FPlayerCharacterData : public FTableRowBase
{
	GENERATED_BODY()

public:
	FPlayerCharacterData() : Level(1), MaxHp(100.0f), Attack(10.0f), NextExp(50.0f){}
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 Level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float MaxHp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float Attack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 NextExp;

};

USTRUCT(BlueprintType)
struct FWeaponData : public FTableRowBase
{
	GENERATED_BODY()

public:
	FWeaponData() :  Level(1), Attack(5), NextExp(50) {}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Info")
		int32 Level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Info")
		float Attack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Info")
		int32 NextExp;
};


UCLASS()
class BOOMPROJECT_API UPlayerGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UPlayerGameInstance();

	FPlayerCharacterData* GetPlayerCharacterData(int32 Level);
	FWeaponData* GetSwordData(int32 Level);
	FWeaponData* GetGunData(int32 Level);

	UDataTable* DataObjectPath(FString DataPath);

private:
	UPROPERTY()
		class UDataTable* PlayerCharacterTable;

	UPROPERTY()
		class UDataTable* SwordDataTable;

	UPROPERTY()
		class UDataTable* GunDataTable;

	
};
