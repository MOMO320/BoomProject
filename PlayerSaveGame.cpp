// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerSaveGame.h"

UPlayerSaveGame::UPlayerSaveGame()
{
	Name = TEXT(PLAYER_NONE_NAME);
	Level = 1;
	Exp = 0;
	Money = 300;
}