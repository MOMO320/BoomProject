// Fill out your copyright notice in the Description page of Project Settings.


#include "GameStartWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/EditableTextBox.h"
#include "Components/TextBlock.h"
#include "PlayerSaveGame.h"

void UGameStartWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	PlayerName = PLAYER_NONE_NAME;

	PlayerSaveData = NewObject<UPlayerSaveGame>();

	NonePlayerPanel = GetWidgetFromNameConstruct<class UCanvasPanel>(TEXT("sys_None_Player_Panel"));
	PlayerPanel = GetWidgetFromNameConstruct<class UCanvasPanel>(TEXT("sys_Player_Panel"));
	GameStartButton = GetWidgetFromNameConstruct<class UButton>(TEXT("sys_GameStart_Btn"));
	PlayerNameConfireButton = GetWidgetFromNameConstruct<class UButton>(TEXT("sys_Confirm_btn"));
	IDErrorAramText = GetWidgetFromNameConstruct<class UTextBlock>(TEXT("sys_IDCheck_txt"));
	PlayerNameText = GetWidgetFromNameConstruct<class UTextBlock>(TEXT("sys_PlayerName_Txt"));
	PlayerNameInputText = GetWidgetFromNameConstruct<class UEditableTextBox>(TEXT("sys_Input_txt"));

	SetPanelEnable(PlayerSaveData->Name.Compare(PlayerName) == 0);

	// Add Delegate Event Fuction
	AddWigetEvent();

}

void UGameStartWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	CheckPlayerName();
}

void UGameStartWidget::PlayerNameConfireClicked()
{
	if (IDErrorAramText->GetVisibility() == ESlateVisibility::Visible)
		return;
	
	PlayerSaveData = NewObject<UPlayerSaveGame>();
	PlayerSaveData->Name = PlayerName;
	PlayerSaveData->Level = 1;
	PlayerSaveData->Exp = 0;
	PlayerSaveData->Money = 300;

	SetPanelEnable(PlayerSaveData->Name.Compare(PLAYER_NONE_NAME) == 0);
}

void UGameStartWidget::GameStartClicked()
{
	// ¹ÌÁ¤
	UGameplayStatics::OpenLevel(GetWorld(), TEXT("OverView"));
}

void UGameStartWidget::AddWigetEvent()
{
	if (GameStartButton->OnClicked.IsBound() == false)
		GameStartButton->OnClicked.AddDynamic(this, &UGameStartWidget::GameStartClicked);

	if (PlayerNameConfireButton->OnClicked.IsBound() == false)
		PlayerNameConfireButton->OnClicked.AddDynamic(this, &UGameStartWidget::PlayerNameConfireClicked);
}

void UGameStartWidget::SetPanelEnable(bool isNonePlayer)
{
	NonePlayerPanel->SetVisibility((isNonePlayer)? ESlateVisibility::Visible : ESlateVisibility::Hidden);
	PlayerPanel->SetVisibility((isNonePlayer == false)? ESlateVisibility::Visible : ESlateVisibility::Hidden);

	if (isNonePlayer) return;
	
	PlayerNameText->SetText(FText::FromString(PlayerSaveData->Name));	
}

void UGameStartWidget::CheckPlayerName()
{
	PlayerName = PlayerNameInputText->GetText().ToString();
	IDErrorAramText->SetVisibility((PlayerName.Len() <= 3 || PlayerName.Len() >= 10) ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
	PlayerNameConfireButton->SetIsEnabled((PlayerName.Len() <= 3 || PlayerName.Len() >= 10) ? false : true);
}


