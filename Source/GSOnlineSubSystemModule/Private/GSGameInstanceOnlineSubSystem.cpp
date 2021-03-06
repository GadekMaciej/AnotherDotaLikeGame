// Fill out your copyright notice in the Description page of Project Settings.


#include "GSGameInstanceOnlineSubSystem.h"

#include "OnlineSubsystemUtils.h"
#include "GSOnlineSubSystemModule/GSOnlineSubSystemModule.h"
#include "Kismet/GameplayStatics.h"

UGSGameInstanceOnlineSubSystem::UGSGameInstanceOnlineSubSystem()
	:
	OnCreateSessionCompleteDelegate(FOnCreateSessionCompleteDelegate::CreateUObject(this, &ThisClass::OnCreateSessionCompleted)),
	OnUpdateSessionCompleteDelegate(FOnUpdateSessionCompleteDelegate::CreateUObject(this, &ThisClass::OnUpdateSessionCompleted)),
	OnStartSessionCompleteDelegate(FOnStartSessionCompleteDelegate::CreateUObject(this, &ThisClass::OnStartSessionCompleted)),
	OnEndSessionCompleteDelegate(FOnStartSessionCompleteDelegate::CreateUObject(this, &ThisClass::OnEndSessionCompleted)),
	OnDestroySessionCompleteDelegate(FOnDestroySessionCompleteDelegate::CreateUObject(this, &ThisClass::OnDestroySessionCompleted)),
	OnFindSessionsCompleteDelegate(FOnFindSessionsCompleteDelegate::CreateUObject(this, &ThisClass::OnFindSessionCompleted)),
	OnJoinSessionCompleteDelegate(FOnJoinSessionCompleteDelegate::CreateUObject(this, &ThisClass::OnJoinSessionCompleted))
{
	
}

void UGSGameInstanceOnlineSubSystem::CreateSession(FString SessionName, int32 NumPublicConnections, bool bIsLANMatch)
{
	UE_LOG(LogGSGIOS, Verbose, TEXT("Session create fired"))
	const IOnlineSessionPtr SessionInterface = Online::GetSessionInterface(GetWorld());
	if (!SessionInterface.IsValid())
	{
		OnCreateSessionCompleteEvent.Broadcast(false);
		return;
	}
	else
	{
		LastSessionSettings = MakeShareable(new FOnlineSessionSettings());
		LastSessionSettings->NumPrivateConnections = 0;
		LastSessionSettings->NumPublicConnections = NumPublicConnections;
		LastSessionSettings->bAllowInvites = true;
		LastSessionSettings->bAllowJoinInProgress = true;
		LastSessionSettings->bAllowJoinViaPresence = true;
		LastSessionSettings->bAllowJoinViaPresenceFriendsOnly = true;
		LastSessionSettings->bIsDedicated = false;
		LastSessionSettings->bUsesPresence = true;
		LastSessionSettings->bIsLANMatch = bIsLANMatch;
		LastSessionSettings->bShouldAdvertise = true;
		
		LastSessionSettings->Set(GS_SETTING_SESSION_NAME, SessionName, EOnlineDataAdvertisementType::ViaOnlineServiceAndPing);
		LastSessionSettings->Set(SETTING_MAPNAME, FString("Your Level Name"), EOnlineDataAdvertisementType::ViaOnlineService);

		OnCreateSessionCompleteDelegateHandle = SessionInterface->AddOnCreateSessionCompleteDelegate_Handle(OnCreateSessionCompleteDelegate);
		

		const ULocalPlayer* LocalPlayer = GetWorld()->GetFirstLocalPlayerFromController();
		if (!SessionInterface->CreateSession(*LocalPlayer->GetPreferredUniqueNetId(), NAME_GameSession, *LastSessionSettings))
		{
			SessionInterface->ClearOnCreateSessionCompleteDelegate_Handle(OnCreateSessionCompleteDelegateHandle);

			OnCreateSessionCompleteEvent.Broadcast(false);
		}
	}
}

void UGSGameInstanceOnlineSubSystem::UpdateSession()
{
	UE_LOG(LogGSGIOS, Verbose, TEXT("Session update fired"))
	const IOnlineSessionPtr SessionInterface = Online::GetSessionInterface(GetWorld());
	if (!SessionInterface.IsValid())
	{
		OnUpdateSessionCompleteEvent.Broadcast(false);
		return;
	}

	TSharedPtr<FOnlineSessionSettings> UpdatedSessionSettings = MakeShareable(new FOnlineSessionSettings(*LastSessionSettings));
	UpdatedSessionSettings->Set(SETTING_MAPNAME, FString("Updated Level Name"), EOnlineDataAdvertisementType::ViaOnlineService);

	OnUpdateSessionCompleteDelegateHandle = SessionInterface->AddOnUpdateSessionCompleteDelegate_Handle(OnUpdateSessionCompleteDelegate);

	if (!SessionInterface->UpdateSession(NAME_GameSession, *UpdatedSessionSettings))
	{
		SessionInterface->ClearOnUpdateSessionCompleteDelegate_Handle(OnUpdateSessionCompleteDelegateHandle);

		OnUpdateSessionCompleteEvent.Broadcast(false);
	}
	else
	{
		LastSessionSettings = UpdatedSessionSettings;
	}
}

void UGSGameInstanceOnlineSubSystem::StartSession()
{
	UE_LOG(LogGSGIOS, Verbose, TEXT("Session start fired"))
	const IOnlineSessionPtr SessionInterface = Online::GetSessionInterface(GetWorld());
	if (!SessionInterface.IsValid())
	{
		OnStartSessionCompleteEvent.Broadcast(false);
		return;
	}

	OnStartSessionCompleteDelegateHandle = SessionInterface->AddOnStartSessionCompleteDelegate_Handle(OnStartSessionCompleteDelegate);

	if (!SessionInterface->StartSession(NAME_GameSession))
	{
		SessionInterface->ClearOnStartSessionCompleteDelegate_Handle(OnStartSessionCompleteDelegateHandle);

		OnStartSessionCompleteEvent.Broadcast(false);
	}
}

void UGSGameInstanceOnlineSubSystem::EndSession()
{
	UE_LOG(LogGSGIOS, Verbose, TEXT("Session end fired"))
	const IOnlineSessionPtr SessionInterface = Online::GetSessionInterface(GetWorld());
	if (!SessionInterface.IsValid())
	{
		OnEndSessionCompleteEvent.Broadcast(false);
		return;
	}

	OnEndSessionCompleteDelegateHandle = SessionInterface->AddOnEndSessionCompleteDelegate_Handle(OnEndSessionCompleteDelegate);

	if (!SessionInterface->EndSession(NAME_GameSession))
	{
		SessionInterface->ClearOnEndSessionCompleteDelegate_Handle(OnEndSessionCompleteDelegateHandle);

		OnEndSessionCompleteEvent.Broadcast(false);
	}
}

void UGSGameInstanceOnlineSubSystem::DestroySession()
{
	UE_LOG(LogGSGIOS, Verbose, TEXT("Session Destroy fired"))
	const IOnlineSessionPtr SessionInterface = Online::GetSessionInterface(GetWorld());
	if (!SessionInterface.IsValid())
	{
		OnDestroySessionCompleteEvent.Broadcast(false);
		return;
	}

	OnDestroySessionCompleteDelegateHandle = SessionInterface->AddOnDestroySessionCompleteDelegate_Handle(OnDestroySessionCompleteDelegate);

	if (!SessionInterface->DestroySession(NAME_GameSession))
	{
		SessionInterface->ClearOnDestroySessionCompleteDelegate_Handle(OnDestroySessionCompleteDelegateHandle);

		OnDestroySessionCompleteEvent.Broadcast(false);
	}
}

void UGSGameInstanceOnlineSubSystem::FindSession(int32 MaxSearchResults, bool bIsLANQuery)
{
	UE_LOG(LogGSGIOS, Verbose, TEXT("Session find fired"))
	const IOnlineSessionPtr SessionInterface = Online::GetSessionInterface(GetWorld());
	if (!SessionInterface.IsValid())
	{
		OnFindSessionsCompleteEvent.Broadcast(TArray<FOnlineSessionSearchResult>(), false);
		return;
	}

	OnFindSessionsCompleteDelegateHandle = SessionInterface->AddOnFindSessionsCompleteDelegate_Handle(OnFindSessionsCompleteDelegate);

	LastSessionSearch = MakeShareable(new FOnlineSessionSearch());
	LastSessionSearch->MaxSearchResults = MaxSearchResults;
	LastSessionSearch->bIsLanQuery = bIsLANQuery;

	LastSessionSearch->QuerySettings.Set(SEARCH_PRESENCE, true, EOnlineComparisonOp::Equals);

	const ULocalPlayer* LocalPlayer = GetWorld()->GetFirstLocalPlayerFromController();
	if (!SessionInterface->FindSessions(*LocalPlayer->GetPreferredUniqueNetId(), LastSessionSearch.ToSharedRef()))
	{
		SessionInterface->ClearOnFindSessionsCompleteDelegate_Handle(OnFindSessionsCompleteDelegateHandle);

		OnFindSessionsCompleteEvent.Broadcast(TArray<FOnlineSessionSearchResult>(), false);
	}
}

void UGSGameInstanceOnlineSubSystem::JoinSession(const FOnlineSessionSearchResult& SessionResult)
{
	UE_LOG(LogGSGIOS, Verbose, TEXT("Session join fired"))
	const IOnlineSessionPtr SessionInterface = Online::GetSessionInterface(GetWorld());
	if (!SessionInterface.IsValid())
	{
		OnJoinSessionCompleteEvent.Broadcast(EOnJoinSessionCompleteResult::UnknownError);
		return;
	}

	OnJoinSessionCompleteDelegateHandle = SessionInterface->AddOnJoinSessionCompleteDelegate_Handle(OnJoinSessionCompleteDelegate);

	const ULocalPlayer* localPlayer = GetWorld()->GetFirstLocalPlayerFromController();
	if (!SessionInterface->JoinSession(*localPlayer->GetPreferredUniqueNetId(), NAME_GameSession, SessionResult))
	{
		SessionInterface->ClearOnJoinSessionCompleteDelegate_Handle(OnJoinSessionCompleteDelegateHandle);

		OnJoinSessionCompleteEvent.Broadcast(EOnJoinSessionCompleteResult::UnknownError);
	}
}

void UGSGameInstanceOnlineSubSystem::OnCreateSessionCompleted(FName SessionName, const bool bIsSuccessful)
{
	UE_LOG(LogGSGIOS, Verbose, TEXT("Session create complete: %s"), bIsSuccessful? TEXT("Successs") : TEXT("failure"))
	const IOnlineSessionPtr SessionInterface = Online::GetSessionInterface(GetWorld());
	if (SessionInterface)
	{
		SessionInterface->ClearOnCreateSessionCompleteDelegate_Handle(OnCreateSessionCompleteDelegateHandle);
	}
	UGameplayStatics::OpenLevel(GetWorld(), "TestLevel", true, "Listen");
	OnCreateSessionCompleteEvent.Broadcast(bIsSuccessful);
}

void UGSGameInstanceOnlineSubSystem::OnUpdateSessionCompleted(FName SessionName, const bool bIsSuccessful)
{
	UE_LOG(LogGSGIOS, Verbose, TEXT("Session update complete: %s"), bIsSuccessful? TEXT("Successs") : TEXT("failure"))
	const IOnlineSessionPtr SessionInterface = Online::GetSessionInterface(GetWorld());
	if (SessionInterface)
	{
		SessionInterface->ClearOnUpdateSessionCompleteDelegate_Handle(OnUpdateSessionCompleteDelegateHandle);
	}

	OnUpdateSessionCompleteEvent.Broadcast(bIsSuccessful);
}

void UGSGameInstanceOnlineSubSystem::OnStartSessionCompleted(FName SessionName, bool bIsSuccessful)
{
	UE_LOG(LogGSGIOS, Verbose, TEXT("Session start complete: %s"), bIsSuccessful? TEXT("Successs") : TEXT("failure"))
	const IOnlineSessionPtr SessionInterface = Online::GetSessionInterface(GetWorld());
	if (SessionInterface)
	{
		SessionInterface->ClearOnStartSessionCompleteDelegate_Handle(OnStartSessionCompleteDelegateHandle);
	}

	OnStartSessionCompleteEvent.Broadcast(bIsSuccessful);
}

void UGSGameInstanceOnlineSubSystem::OnEndSessionCompleted(FName SessionName, const bool bIsSuccessful)
{
	UE_LOG(LogGSGIOS, Verbose, TEXT("Session end complete: %s"), bIsSuccessful? TEXT("Successs") : TEXT("failure"))
	const IOnlineSessionPtr SessionInterface = Online::GetSessionInterface(GetWorld());;
	if (SessionInterface)
	{
		SessionInterface->ClearOnEndSessionCompleteDelegate_Handle(OnEndSessionCompleteDelegateHandle);
	}

	OnEndSessionCompleteEvent.Broadcast(bIsSuccessful);
}

void UGSGameInstanceOnlineSubSystem::OnDestroySessionCompleted(FName SessionName, const bool bIsSuccessful)
{
	UE_LOG(LogGSGIOS, Verbose, TEXT("Session destroy complete: %s"), bIsSuccessful? TEXT("Successs") : TEXT("failure"))
	const IOnlineSessionPtr SessionInterface = Online::GetSessionInterface(GetWorld());
	if (SessionInterface)
	{
		SessionInterface->ClearOnDestroySessionCompleteDelegate_Handle(OnDestroySessionCompleteDelegateHandle);
	}

	OnDestroySessionCompleteEvent.Broadcast(bIsSuccessful);
}

void UGSGameInstanceOnlineSubSystem::OnFindSessionCompleted(const bool bIsSuccessful)
{
	UE_LOG(LogGSGIOS, Verbose, TEXT("Session find complete: %s"), bIsSuccessful? TEXT("Successs") : TEXT("failure"))
	const IOnlineSessionPtr SessionInterface = Online::GetSessionInterface(GetWorld());
	if (SessionInterface)
	{
		SessionInterface->ClearOnFindSessionsCompleteDelegate_Handle(OnFindSessionsCompleteDelegateHandle);
	}

	if (LastSessionSearch->SearchResults.Num() <= 0)
	{
		OnFindSessionsCompleteEvent.Broadcast(TArray<FOnlineSessionSearchResult>(), bIsSuccessful);
		return;
	}

	OnFindSessionsCompleteEvent.Broadcast(LastSessionSearch->SearchResults, bIsSuccessful);
}

void UGSGameInstanceOnlineSubSystem::OnJoinSessionCompleted(FName SessionName, EOnJoinSessionCompleteResult::Type Result)
{
	UE_LOG(LogGSGIOS, Verbose, TEXT("Session join complete: %s"), Result == EOnJoinSessionCompleteResult::Type::Success? TEXT("Successs") : TEXT("failure"))
	const IOnlineSessionPtr SessionInterface = Online::GetSessionInterface(GetWorld());
	if (SessionInterface)
	{
		SessionInterface->ClearOnJoinSessionCompleteDelegate_Handle(OnJoinSessionCompleteDelegateHandle);
	}
	TryTravelToCurrentSession();
	OnJoinSessionCompleteEvent.Broadcast(Result);
}

bool UGSGameInstanceOnlineSubSystem::TryTravelToCurrentSession()
{
	UE_LOG(LogGSGIOS, Verbose, TEXT("Session travel fired"))
	const IOnlineSessionPtr sessionInterface = Online::GetSessionInterface(GetWorld());
	if (!sessionInterface.IsValid())
	{
		return false;
	}

	FString ConnectString;
	if (!sessionInterface->GetResolvedConnectString(NAME_GameSession, ConnectString))
	{
		return false;
	}

	APlayerController* playerController = GetWorld()->GetFirstPlayerController();
	playerController->ClientTravel(ConnectString, TRAVEL_Absolute);
	return true;
}
