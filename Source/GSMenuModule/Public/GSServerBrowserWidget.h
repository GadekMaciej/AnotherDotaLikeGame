// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GSUserWidgetBase.h"
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
	

	public:

	// test
	UFUNCTION(BlueprintCallable)
	void ServerListTestFunction();
	
	UFUNCTION(BlueprintCallable)
	void OnServerListEntryClicked(UObject* Item);

	UFUNCTION(BlueprintCallable)
	void AddServerListItem();
	
	protected:
	UFUNCTION(BlueprintCallable)
	void OnMainMenuButtonClicked();
	UFUNCTION(BlueprintCallable)
	void OnHostButtonClicked();
	
	private:

};
