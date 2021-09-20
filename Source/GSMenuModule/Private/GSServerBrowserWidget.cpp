// Fill out your copyright notice in the Description page of Project Settings.


#include "GSServerBrowserWidget.h"

#include "GSButtonWidget.h"
#include "GSGameInstanceOnlineSubSystem.h"
#include "GSServerBrowserEntryObject.h"
#include "Components/Button.h"
#include "Components/ListView.h"

void UGSServerBrowserWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	MainMenuButton->ButtonElement->OnClicked.AddDynamic(this, &ThisClass::OnMainMenuButtonClicked);
	HostButton->ButtonElement->OnClicked.AddDynamic(this, &ThisClass::OnHostButtonClicked);
	RefreshButton->ButtonElement->OnClicked.AddDynamic(this, &ThisClass::OnRefreshButtonClicked);
	ServerListView->OnItemClicked().AddUObject(this, &ThisClass::OnServerListEntryClicked);

	ServerListView->OnItemClicked().AddUObject(this, &ThisClass::OnEntryClicked);
	
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
		GIOS->FindSession();
	}
}

void UGSServerBrowserWidget::RefreshServerList(const TArray<class FOnlineSessionSearchResult>& SessionResults, bool bIsSuccessful)
{
	if (bIsSuccessful)
	{
		UE_LOG(LogTemp, Warning, TEXT("session found just fine") );
		for (auto result : SessionResults)
		{
			const FGSServerBrowserEntryStruct EntryData(FText::FromString(result.Session.GetSessionIdStr()));
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

void UGSServerBrowserWidget::OnEntryClicked(UObject* Entry)
{
	UGSServerBrowserEntryObject* EntryCasted = Cast<UGSServerBrowserEntryObject>(Entry);
	if (EntryCasted)
	{
		UE_LOG(LogTemp, Warning, TEXT("server entry on clicked fired"));
	}
}
