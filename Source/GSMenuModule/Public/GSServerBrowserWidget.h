// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GSUserWidgetBase.h"
#include "OnlineSubsystemUtils.h"
#include "GSServerBrowserWidget.generated.h"

/**
 * 
 */

DECLARE_DELEGATE(FOnRefreshButtonClicked)
DECLARE_DELEGATE(FOnJoinButtonClicked)
DECLARE_DELEGATE(FOnHostButtonClicked)
DECLARE_DELEGATE(FOnMainMenuButtonClicked)


UCLASS(Abstract)
class GSMENUMODULE_API UGSServerBrowserWidget : public UGSUserWidgetBase
{
	GENERATED_BODY()
	
	protected:
	virtual void NativeOnInitialized() override;
	
	public:
	FOnRefreshButtonClicked FOnRefreshButtonClickedEvent;
	FOnJoinButtonClicked FOnJoinButtonClickedEvent;
	FOnHostButtonClicked FOnHostButtonClickedEvent;
	FOnMainMenuButtonClicked FOnMainMenuButtonClickedEvent;
	
	protected:
	
	private:
	UPROPERTY(meta=(BindWidget))
	class UGSButtonWidget* RefreshButton;
	
	UPROPERTY(meta=(BindWidget))
	UGSButtonWidget* JoinButton;

	UPROPERTY(meta=(BindWidget))
	UGSButtonWidget* HostButton;

	UPROPERTY(meta=(BindWidget))
	UGSButtonWidget* MainMenuButton;

	UPROPERTY(meta=(BindWidget))
	class UListView* ServerListView;

	TArray<FOnlineSessionSearchResult> LastSessionSearchResults;
	
	public:	
	UFUNCTION(BlueprintCallable)
	void OnServerListEntryClicked(UObject* Item);
	
	virtual void OnSwitch() override;
	
	protected:
	UFUNCTION(BlueprintCallable)
	void OnRefreshButtonClicked();
	UFUNCTION(BlueprintCallable)
	void OnJoinButtonClicked();
	UFUNCTION(BlueprintCallable)
	void OnMainMenuButtonClicked();
	UFUNCTION(BlueprintCallable)
	void OnHostButtonClicked();
	// TODO make below function UFUNCTION, by using Ustruct that wraps FOnlineSessionSearchResult.
	void RefreshServerList(const TArray<FOnlineSessionSearchResult>& SessionResults, bool bIsSuccessful);
};
