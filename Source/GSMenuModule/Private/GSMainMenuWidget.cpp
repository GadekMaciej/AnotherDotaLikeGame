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
	MultiplayerButton->ButtonElement->OnClicked.AddDynamic(this, &UGSMainMenuWidget::MultiplayerButtonOnClicked);
	QuitButton->ButtonElement->OnClicked.AddDynamic(this, &UGSMainMenuWidget::QuitGame);
}

void UGSMainMenuWidget::SynchronizeProperties()
{
	Super::SynchronizeProperties();
	if(TitleTextBlock)
	{
		TitleTextBlock->SetText(TitleText);
	}
}

void UGSMainMenuWidget::QuitGame()
{
	FGenericPlatformMisc::RequestExit(false);
}

void UGSMainMenuWidget::MultiplayerButtonOnClicked()
{
	NavigateToWidget(ServerBrowserWidgetClass);
}

