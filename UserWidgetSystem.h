// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/CanvasPanel.h"
#include "Components/EditableTextBox.h"
#include "UserWidgetSystem.generated.h"

/**
 * 
 */

UCLASS()
class BOOMPROJECT_API UUserWidgetSystem : public UUserWidget
{
	GENERATED_BODY()

public:
	template <typename T>
	T* GetWidgetFromNameConstruct(const FName& WidgetName)
	{
		T* temp = Cast<T>(GetWidgetFromName(WidgetName));
		
		if (temp == nullptr)
		{
			return nullptr;
		}

		return temp;
	}

};
