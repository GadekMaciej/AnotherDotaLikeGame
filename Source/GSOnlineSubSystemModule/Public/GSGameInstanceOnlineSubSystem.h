// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "GSGameInstanceOnlineSubSystem.generated.h"

/**
 * 
 */
#define GS_SETTING_SESSION_NAME FName(TEXT("SessionName"))

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGSOnCreateSessionComplete, bool, bIsSuccessful);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGSOnUpdateSessionComplete, bool, bIsSuccessful);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGSOnStartSessionComplete, bool, bIsSuccessful);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGSOnEndSessionComplete, bool, bIsSuccessful);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGSOnDestroySessionComplete, bool, bIsSuccessful);
DECLARE_MULTICAST_DELEGATE_TwoParams(FGSOnFindSessionsComplete, const TArray<FOnlineSessionSearchResult>& SessionResults, bool bIsSuccessful);
DECLARE_MULTICAST_DELEGATE_OneParam(FGSOnJoinSessionComplete, EOnJoinSessionCompleteResult::Type Result);

UCLASS()
class GSONLINESUBSYSTEMMODULE_API UGSGameInstanceOnlineSubSystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
	public:
	UGSGameInstanceOnlineSubSystem();
	FGSOnCreateSessionComplete OnCreateSessionCompleteEvent;
	FGSOnUpdateSessionComplete OnUpdateSessionCompleteEvent;
	FGSOnStartSessionComplete OnStartSessionCompleteEvent;
	FGSOnEndSessionComplete OnEndSessionCompleteEvent;
	FGSOnDestroySessionComplete OnDestroySessionCompleteEvent;
	FGSOnFindSessionsComplete OnFindSessionsCompleteEvent;
	FGSOnJoinSessionComplete OnJoinSessionCompleteEvent;

	public:
	void CreateSession(FString SessionName = TEXT("SessionDefaultName"), int32 NumPublicConnections = 2, bool bIsLANMatch = false);
	void UpdateSession();
	void StartSession();
	void EndSession();
	void DestroySession();
	void FindSession(int32 MaxSearchResults = 32, bool bIsLANQuery = true);
	void JoinSession(const FOnlineSessionSearchResult& SessionResult);
	
	protected:
	FOnCreateSessionCompleteDelegate OnCreateSessionCompleteDelegate;
	FDelegateHandle OnCreateSessionCompleteDelegateHandle;
	
	FOnUpdateSessionCompleteDelegate OnUpdateSessionCompleteDelegate;
	FDelegateHandle OnUpdateSessionCompleteDelegateHandle;
	
	FOnStartSessionCompleteDelegate OnStartSessionCompleteDelegate;
	FDelegateHandle OnStartSessionCompleteDelegateHandle;

	FOnEndSessionCompleteDelegate OnEndSessionCompleteDelegate;
	FDelegateHandle OnEndSessionCompleteDelegateHandle;
	
	FOnDestroySessionCompleteDelegate OnDestroySessionCompleteDelegate;
	FDelegateHandle OnDestroySessionCompleteDelegateHandle;
	
	FOnFindSessionsCompleteDelegate OnFindSessionsCompleteDelegate;
	FDelegateHandle OnFindSessionsCompleteDelegateHandle;

	FOnJoinSessionCompleteDelegate OnJoinSessionCompleteDelegate;
	FDelegateHandle OnJoinSessionCompleteDelegateHandle;
	
	TSharedPtr<FOnlineSessionSettings> LastSessionSettings;
	TSharedPtr<FOnlineSessionSearch> LastSessionSearch;
		
	protected:
	void OnCreateSessionCompleted(FName SessionName, const bool bIsSuccessful);
	void OnUpdateSessionCompleted(FName SessionName, const bool bIsSuccessful);
	void OnStartSessionCompleted(FName SessionName, const bool bIsSuccessful);
	void OnEndSessionCompleted(FName SessionName, const bool bIsSuccessful);
	void OnDestroySessionCompleted(FName SessionName, const bool bIsSuccessful);
	void OnFindSessionCompleted(const bool bIsSuccessful);
	void OnJoinSessionCompleted(FName SessionName, EOnJoinSessionCompleteResult::Type Result);
	bool TryTravelToCurrentSession();
};
