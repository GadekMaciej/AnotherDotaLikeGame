// Fill out your copyright notice in the Description page of Project Settings.


#include "GSGameInstance.h"

#include "GSGameInstanceOnlineSubSystem.h"

void UGSGameInstance::Init()
{
	Super::Init();
	UGSGameInstanceOnlineSubSystem* GIOS = GetSubsystem<UGSGameInstanceOnlineSubSystem>();
	GIOS->OnCreateSessionCompleteEvent.AddDynamic(this, &UGSGameInstance::WasSessionCreated);
}

void UGSGameInstance::WasSessionCreated(bool bIsSuccessful)
{
	if(bIsSuccessful)
	{
		UE_LOG(LogTemp, Warning, TEXT("session created just fine") );
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Session failed to create") );
	}

}
