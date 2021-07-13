// Fill out your copyright notice in the Description page of Project Settings.


#include "GameStartController.h"
#include "GameStartWidget.h"

AGameStartController::AGameStartController()
{
	static ConstructorHelpers::FClassFinder<UGameStartWidget> UI_START_C(TEXT("/Game/Widget/GameStartWidget.GameStartWidget_C"));

	if (UI_START_C.Succeeded())
	{
		GameStartWidgetClass = UI_START_C.Class;
	}
}

void AGameStartController::BeginPlay()
{
	Super::BeginPlay();

	SetInputMode(UIInputMode);
	bShowMouseCursor = true;

	GameStartWidget = CreateWidget<UGameStartWidget>(this, GameStartWidgetClass);
	
	if (GameStartWidget == nullptr) return;

	GameStartWidget->AddToViewport(1);
}

