// Fill out your copyright notice in the Description page of Project Settings.


#include "GSServerBrowserEntryWidget.h"

#include "GSServerBrowserEntryObject.h"
#include "Components/TextBlock.h"


void UGSServerBrowserEntryWidget::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	IUserObjectListEntry::NativeOnListItemObjectSet(ListItemObject);
	UGSServerBrowserEntryObject* EntryData = Cast<UGSServerBrowserEntryObject>(ListItemObject);
	if(ensureAlwaysMsgf(EntryData, TEXT("Server Browser entry data cast failed")))
	{
		SessionNameTextField->SetText(EntryData->EntryData.SessionName);
		SessionHostTextField->SetText(EntryData->EntryData.HostName);
		SessionPlayerCount->SetText(FText::FromString(FString::Printf(TEXT("%d/%d"), EntryData->EntryData.CurrentNumberOfPlayers, EntryData->EntryData.MaxNumberOfPlayers)));
	}
}
