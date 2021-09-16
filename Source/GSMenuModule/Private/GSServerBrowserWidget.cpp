// Fill out your copyright notice in the Description page of Project Settings.


#include "GSServerBrowserWidget.h"

#include "GSButtonWidget.h"
#include "GSServerBrowserEntryObject.h"
#include "Components/Button.h"
#include "Components/ListView.h"

void UGSServerBrowserWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	MainMenuButton->ButtonElement->OnClicked.AddDynamic(this, &UGSServerBrowserWidget::MultiplayerButtonOnClicked);
	ServerListView->OnItemClicked().AddUObject(this, &UGSServerBrowserWidget::OnServerListEntryClicked);
	ServerListTestFunction();
}

void UGSServerBrowserWidget::MultiplayerButtonOnClicked()
{
	NavigateToWidget(MainMenuWidget);
}

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
	NavigateToWidget(MainMenuWidget);
}
