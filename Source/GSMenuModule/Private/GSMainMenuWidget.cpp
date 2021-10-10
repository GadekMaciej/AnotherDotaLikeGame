// Fill out your copyright notice in the Description page of Project Settings.


#include "GSMainMenuWidget.h"

#include "GSButtonWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"

void UGSMainMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UGSMainMenuWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	MultiplayerButton->ButtonElement->OnClicked.AddDynamic(this, &UGSMainMenuWidget::OnMultiplayerButtonClicked);
	QuitButton->ButtonElement->OnClicked.AddDynamic(this, &UGSMainMenuWidget::OnQuitButtonClicked);
}

void UGSMainMenuWidget::SynchronizeProperties()
{
	Super::SynchronizeProperties();
	if(TitleTextBlock)
	{
		TitleTextBlock->SetText(TitleText);
	}
}

void UGSMainMenuWidget::OnQuitButtonClicked()
{
	if(!OnQuitButtonClickedEvent.ExecuteIfBound())
	{
		checkNoEntry();
	}
}

void UGSMainMenuWidget::OnMultiplayerButtonClicked()
{
	if(!OnMultiplayerButtonClickedEvent.ExecuteIfBound())
	{
		checkNoEntry();
	}
}

