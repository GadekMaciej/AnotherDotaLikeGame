// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GSUserWidgetBase.h"
#include "GSServerBrowserWidget.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class GSMENUMODULE_API UGSServerBrowserWidget : public UGSUserWidgetBase
{
	GENERATED_BODY()
	public:
	virtual void NativeOnInitialized() override;
public:
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
	
	UPROPERTY(EditDefaultsOnly, NoClear, Category="GS|Navigation")
	TSubclassOf<UGSUserWidgetBase> MainMenuWidget;

	public:
	UFUNCTION(BlueprintCallable)
	void MultiplayerButtonOnClicked();

	UFUNCTION(BlueprintCallable)
	void ServerListTestFunction();
	
	UFUNCTION(BlueprintCallable)
	void OnServerListEntryClicked(UObject* Item);
	
};
