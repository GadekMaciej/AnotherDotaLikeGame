// Fill out your copyright notice in the Description page of Project Settings.


#include "GSMainMenuWidget.h"

#include "Components/TextBlock.h"

void UGSMainMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UGSMainMenuWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void UGSMainMenuWidget::SynchronizeProperties()
{
	Super::SynchronizeProperties();
	if(TitleTextBlock)
	{
		TitleTextBlock->SetText(TitleText);
	}
}
