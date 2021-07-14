// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "EngineMinimal.h"
#include <Kismet/GameplayStatics.h>

#define PLAYER_NONE_NAME "P1"

DECLARE_LOG_CATEGORY_EXTERN(BoomProject, Log, All);

#define MYLOG_CALLINFO (FString(__FUNCTION__) + TEXT("(") + FString::FromInt(__LINE__) + TEXT(")"))
#define MYLOG(Verbosity , Format, ...) UE_LOG(BoomProject , Verbosity , TEXT("%s%s"), *MYLOG_CALLINFO, *FString::Printf(Format , ##__VA_ARGS__))
#define MYCHECK(Expr, ...) {if(!(Expr)) {MYLOG(Error, TEXT("ASSERTION : %s"), TEXT("'"#Expr"'")); return __VA_ARGS__;}}


UENUM(BlueprintType)
enum class EWeaponMode : uint8
{
	SWORD,
	GUN,
};