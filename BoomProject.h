// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "EngineMinimal.h"
#include <Kismet/GameplayStatics.h>

#define PLAYER_NONE_NAME "P1"

DECLARE_LOG_CATEGORY_EXTERN(BoomProject, Log, All);

#define MYLOG_CALLINFO (FString(__FUNCTION__) + TEXT("(") + FString::FromInt(__LINE__) + TEXT(")"))
#define MYLOG(Verbosity , Format, ...) UELOG(BoomProject , Verbosity , TEXT("%s%s"), *MYLOG_CALLINFO, *FString::Printf(Format , ##__VA_ARGS__))
#define MYCHECK(Expr, ...) {if(!(Expr)){MYLOG(Error , TEXT("ASSERTION : %s"), TEXT("'"#Expr"'")); return __VA_ARGS__;}}


USTRUCT(BlueprintType)
struct FPlayerWeaponInfo
{
	GENERATED_BODY()

public:
	FPlayerWeaponInfo() : Level(1), Attack(5.0f), Exp(0), MeshAsset("") {}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Info")
		int32 Level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Info")
		float Attack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Info")
		int32 Exp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Info")
		FString MeshAsset;
};

enum class EWeaponMode
{
	SWORD,
	GUN,
	MAGIC
};