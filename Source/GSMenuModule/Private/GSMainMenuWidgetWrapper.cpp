// Fill out your copyright notice in the Description page of Project Settings.


#include "GSMainMenuWidgetWrapper.h"

#include "GSMainMenuWidget.h"
#include "GSServerBrowserWidget.h"
#include "GSHostServerWidget.h"
#include "Components/WidgetSwitcher.h"

void UGSMainMenuWidgetWrapper::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	BindDelegates();
	SwitchWidget(MainMenuWidgetSwitcher, SwitcherWidgetIndex::MainMenuWidget);
}

void UGSMainMenuWidgetWrapper::SwitchWidget(UWidgetSwitcher* Widget, SwitcherWidgetIndex Index)
{
	const int32 IndexToInt32 = static_cast<int32>(Index);
	Widget->SetActiveWidgetIndex(IndexToInt32);
}

void UGSMainMenuWidgetWrapper::BindDelegates()
{
	MainMenuWidget->OnMultiplayerButtonClickedEvent
	.BindUObject(this, &ThisClass::SwitchWidget, MainMenuWidgetSwitcher, SwitcherWidgetIndex::ServerBrowserWidget);
	MainMenuWidget->OnQuitButtonClickedEvent
	.BindLambda([]()
	{
		FGenericPlatformMisc::RequestExit(false);
	});

	ServerBrowserWidget->FOnHostButtonClickedEvent
	.BindUObject(this, &ThisClass::SwitchWidget, MainMenuWidgetSwitcher, SwitcherWidgetIndex::HostServerWidget);
	ServerBrowserWidget->FOnMainMenuButtonClickedEvent
	.BindUObject(this, &ThisClass::SwitchWidget, MainMenuWidgetSwitcher, SwitcherWidgetIndex::MainMenuWidget);

	HostServerWidget->FOnBackButtonClickedEvent
	.BindUObject(this, &ThisClass::SwitchWidget, MainMenuWidgetSwitcher, SwitcherWidgetIndex::ServerBrowserWidget);
	HostServerWidget->FOnHostButtonClickedEvent
	.AddLambda([]()
	{
		UE_LOG(LogTemp, Warning, TEXT("Hosting is not yet implemented"));
	});
}
