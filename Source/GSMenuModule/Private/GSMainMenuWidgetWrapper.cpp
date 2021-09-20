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
	SwitchWidget(MainMenuWidgetSwitcher, SwitcherWidgetIndex::MainMenuWidget);
}

void UGSMainMenuWidgetWrapper::SwitchWidget(UWidgetSwitcher* Widget, SwitcherWidgetIndex Index)
{
	const int32 IndexToInt32 = static_cast<int32>(Index);
	Widget->SetActiveWidgetIndex(IndexToInt32);
	UGSUserWidgetBase* ActiveWidget = Cast<UGSUserWidgetBase>(Widget->GetWidgetAtIndex(IndexToInt32));
	if (ActiveWidget)
	{
		ActiveWidget->OnSwitch();
	}
}

void UGSMainMenuWidgetWrapper::BindDelegates()
{
	UGSGameInstanceOnlineSubSystem* GIOS = GetGameInstance()->GetSubsystem<UGSGameInstanceOnlineSubSystem>();
	
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
	
	//TODO this is bad, hardcoded values. Probably only way is to change delegate signature.
	ServerBrowserWidget->FOnRefreshButtonClickedEvent
	.BindUObject(GIOS, &UGSGameInstanceOnlineSubSystem::FindSession, 10, true);

	HostServerWidget->FOnBackButtonClickedEvent
	.BindUObject(this, &ThisClass::SwitchWidget, MainMenuWidgetSwitcher, SwitcherWidgetIndex::ServerBrowserWidget);
	HostServerWidget->FOnHostButtonClickedEvent
	.AddLambda([]()
	{
		UE_LOG(LogTemp, Warning, TEXT("Hosting is not yet implemented"));
	});
	
	HostServerWidget->FOnHostButtonClickedEvent
	.AddUObject(GIOS, &UGSGameInstanceOnlineSubSystem::CreateSession, 4, true);
}
