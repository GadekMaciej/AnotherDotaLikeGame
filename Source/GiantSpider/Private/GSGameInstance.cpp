// Fill out your copyright notice in the Description page of Project Settings.


#include "GSGameInstance.h"

#include "GSGameInstanceOnlineSubSystem.h"
#include "OnlineSubsystem.h"

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
		UE_LOG(LogTemp, Warning, TEXT("Session joined successful"))
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Error, Could not join the session"))
	}
}

void UGSGameInstance::OnStart()
{
	Super::OnStart();
	LogCurrentOnlineSubsystem();
}

void UGSGameInstance::LogCurrentOnlineSubsystem()
{
	IOnlineSubsystem* OSS = IOnlineSubsystem::Get();
	if (OSS)
	{
		FString SubsystemName = OSS->GetSubsystemName().ToString();
		UE_LOG(LogTemp, Warning, TEXT("Loaded Subsystem: %s"), *SubsystemName);
	}
}
