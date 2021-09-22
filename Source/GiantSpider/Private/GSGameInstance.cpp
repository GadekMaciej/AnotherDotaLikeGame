// Fill out your copyright notice in the Description page of Project Settings.


#include "GSGameInstance.h"

#include "GSGameInstanceOnlineSubSystem.h"
#include "Kismet/GameplayStatics.h"

void UGSGameInstance::Init()
{
	Super::Init();
	UGSGameInstanceOnlineSubSystem* GIOS = GetSubsystem<UGSGameInstanceOnlineSubSystem>();
	GIOS->OnCreateSessionCompleteEvent.AddDynamic(this, &UGSGameInstance::OnPlayerSessionCreated);
	GIOS->OnJoinSessionCompleteEvent.AddUObject(this, &UGSGameInstance::OnPlayerSessionJoined);
}

void UGSGameInstance::OnPlayerSessionCreated(bool bIsSuccessful)
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

void UGSGameInstance::OnPlayerSessionJoined(EOnJoinSessionCompleteResult::Type Result)
{
	if (Result == EOnJoinSessionCompleteResult::Type::Success)
	{
		APlayerController* PC = GetFirstLocalPlayerController();
		if (PC)
		{
			//PC->ClientTravel();
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Error, Could not join the session"))
	}
}
