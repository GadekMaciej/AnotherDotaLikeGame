// Fill out your copyright notice in the Description page of Project Settings.


#include "GSServerBrowserWidget.h"

#include "GSButtonWidget.h"
#include "GSServerBrowserEntryObject.h"
#include "Components/Button.h"
#include "Components/ListView.h"

void UGSServerBrowserWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	MainMenuButton->ButtonElement->OnClicked.AddDynamic(this, &UGSServerBrowserWidget::OnMainMenuButtonClicked);
	HostButton->ButtonElement->OnClicked.AddDynamic(this, &UGSServerBrowserWidget::OnHostButtonClicked);
	ServerListView->OnItemClicked().AddUObject(this, &UGSServerBrowserWidget::OnServerListEntryClicked);
	ServerListTestFunction();
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

// functions below are placeholders for testing listview widget
void UGSServerBrowserWidget::ServerListTestFunction()
{
	for(int32 i = 0; i < 25; i++)
	{
		UGSServerBrowserEntryObject* EntryObject = NewObject<UGSServerBrowserEntryObject>();
		ServerListView->AddItem(EntryObject);
	}
}

void UGSServerBrowserWidget::OnServerListEntryClicked(UObject* Item)
{
	if(!FOnMainMenuButtonClickedEvent.ExecuteIfBound())
	{
		checkNoEntry();
	}
}

void UGSServerBrowserWidget::AddServerListItem()
{
}

// ^^^
