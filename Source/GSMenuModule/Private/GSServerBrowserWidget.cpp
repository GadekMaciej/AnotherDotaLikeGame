// Fill out your copyright notice in the Description page of Project Settings.


#include "GSServerBrowserWidget.h"

#include "GSButtonWidget.h"
#include "GSGameInstanceOnlineSubSystem.h"
#include "GSServerBrowserEntryObject.h"
#include "Components/Button.h"
#include "Components/ListView.h"
#include "Components/WidgetInteractionComponent.h"

void UGSServerBrowserWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	MainMenuButton->ButtonElement->OnClicked.AddDynamic(this, &ThisClass::OnMainMenuButtonClicked);
	HostButton->ButtonElement->OnClicked.AddDynamic(this, &ThisClass::OnHostButtonClicked);
	RefreshButton->ButtonElement->OnClicked.AddDynamic(this, &ThisClass::OnRefreshButtonClicked);
	JoinButton->ButtonElement->OnClicked.AddDynamic(this, &ThisClass::OnJoinButtonClicked);
	UGSGameInstanceOnlineSubSystem* GIOS = GetGameInstance()->GetSubsystem<UGSGameInstanceOnlineSubSystem>();
	GIOS->OnFindSessionsCompleteEvent.AddUObject(this, &ThisClass::RefreshServerList);
}

void UGSServerBrowserWidget::OnMainMenuButtonClicked()
{
	if(!FOnMainMenuButtonClickedEvent.ExecuteIfBound())
	{
		checkNoEntry();
	}
}

void UGSServerBrowserWidget::OnHostButtonClicked()
{
	if(!FOnHostButtonClickedEvent.ExecuteIfBound())
	{
		checkNoEntry();
	}
}

void UGSServerBrowserWidget::OnServerListEntryClicked(UObject* Item)
{
	if(!FOnMainMenuButtonClickedEvent.ExecuteIfBound())
	{
		checkNoEntry();
	}
}

void UGSServerBrowserWidget::OnSwitch()
{
	Super::OnSwitch();
	ServerListView->ClearListItems();
	UGSGameInstanceOnlineSubSystem* GIOS = GetGameInstance()->GetSubsystem<UGSGameInstanceOnlineSubSystem>();
	if (GIOS)
	{
		GIOS->FindSession(60, false);
	}
	ServerListView->AddItem(NewObject<UGSServerBrowserEntryObject>());
	ServerListView->AddItem(NewObject<UGSServerBrowserEntryObject>());
	ServerListView->AddItem(NewObject<UGSServerBrowserEntryObject>());
}

void UGSServerBrowserWidget::RefreshServerList(const TArray<FOnlineSessionSearchResult>& SessionResults, bool bIsSuccessful)
{
	LastSessionSearchResults = SessionResults;
	if (bIsSuccessful)
	{
		UE_LOG(LogTemp, Warning, TEXT("session found just fine") );
		for (auto Session : SessionResults)
		{
			FGSServerBrowserEntryStruct EntryData;
			EntryData.SessionId = FText::FromString(Session.Session.SessionInfo->GetSessionId().ToString());
			FString TempSessionName;
			if(Session.Session.SessionSettings.Get(GS_SETTING_SESSION_NAME, TempSessionName))
			{
				EntryData.SessionName = FText::FromString(TempSessionName);
			}
			else
			{
				checkNoEntry()
			}
			EntryData.HostName = FText::FromString(Session.Session.OwningUserName);
			EntryData.MaxNumberOfPlayers = Session.Session.SessionSettings.NumPublicConnections;
			EntryData.CurrentNumberOfPlayers = EntryData.MaxNumberOfPlayers - Session.Session.NumOpenPublicConnections; 
			UGSServerBrowserEntryObject* EntryObject = NewObject<UGSServerBrowserEntryObject>();
			EntryObject->EntryData = EntryData;
			ServerListView->AddItem(EntryObject);
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("session not found just fine") );
		//TODO prompt, 'could not refresh server list'
	}
}

void UGSServerBrowserWidget::OnRefreshButtonClicked()
{
	ServerListView->ClearListItems();
	if(!FOnRefreshButtonClickedEvent.ExecuteIfBound())
	{
		checkNoEntry();
	}
}

void UGSServerBrowserWidget::OnJoinButtonClicked()
{
	UGSServerBrowserEntryObject* SelectedEntryItem = ServerListView->GetSelectedItem<UGSServerBrowserEntryObject>();
	if(SelectedEntryItem)
	{
		UE_LOG(LogTemp, Warning, TEXT("There is A selected Item"));
		UGSGameInstanceOnlineSubSystem* GIOS = GetGameInstance()->GetSubsystem<UGSGameInstanceOnlineSubSystem>();
		if (GIOS)
		{
			const int32 SessionIndex = ServerListView->GetIndexForItem(SelectedEntryItem);
			FOnlineSessionSearchResult SelectedSession = LastSessionSearchResults[SessionIndex];
			GIOS->JoinSession(SelectedSession);
		}
	}else
	{
		UE_LOG(LogTemp, Warning, TEXT("There is no selected Item"));
	}
}

