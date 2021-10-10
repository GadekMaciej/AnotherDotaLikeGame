// Fill out your copyright notice in the Description page of Project Settings.


#include "GSMainMenuWidgetWrapper.h"

#include "GSGameInstanceOnlineSubSystem.h"
#include "GSMainMenuWidget.h"
#include "GSServerBrowserWidget.h"
#include "GSHostServerWidget.h"
#include "Components/WidgetSwitcher.h"

void UGSMainMenuWidgetWrapper::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	BindDelegates();
	SwitchWidget(MainMenuWidgetSwitcher, MainMenuWidget);
}

void UGSMainMenuWidgetWrapper::SwitchWidget(UWidgetSwitcher* Widget, UGSUserWidgetBase* Index)
{

	Widget->SetActiveWidget(Index);
	Index->OnSwitch();
}

void UGSMainMenuWidgetWrapper::BindDelegates()
{
	UGSGameInstanceOnlineSubSystem* GIOS = GetGameInstance()->GetSubsystem<UGSGameInstanceOnlineSubSystem>();
	
	MainMenuWidget->OnMultiplayerButtonClickedEvent
	.BindUObject(this, &ThisClass::SwitchWidget, MainMenuWidgetSwitcher, (UGSUserWidgetBase*)ServerBrowserWidget);
	MainMenuWidget->OnQuitButtonClickedEvent
	.BindLambda([]()
	{
		FGenericPlatformMisc::RequestExit(false);
	});

	ServerBrowserWidget->FOnHostButtonClickedEvent
	.BindUObject(this, &ThisClass::SwitchWidget, MainMenuWidgetSwitcher, (UGSUserWidgetBase*)HostServerWidget);
	ServerBrowserWidget->FOnMainMenuButtonClickedEvent
	.BindUObject(this, &ThisClass::SwitchWidget, MainMenuWidgetSwitcher, (UGSUserWidgetBase*)MainMenuWidget);
	
	// TODO this is bad, hardcoded values. Probably only way is to change delegate signature.
	ServerBrowserWidget->FOnRefreshButtonClickedEvent
	.BindUObject(GIOS, &UGSGameInstanceOnlineSubSystem::FindSession, 300, false);
	
	HostServerWidget->FOnBackButtonClickedEvent
	.BindUObject(this, &ThisClass::SwitchWidget, MainMenuWidgetSwitcher, (UGSUserWidgetBase*)ServerBrowserWidget);
	HostServerWidget->FOnHostButtonClickedEvent
	.AddUObject(GIOS, &UGSGameInstanceOnlineSubSystem::CreateSession, 2, false);
	
}
