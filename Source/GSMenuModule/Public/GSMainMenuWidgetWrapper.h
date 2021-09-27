// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GSUserWidgetBase.h"
#include "GSMainMenuWidgetWrapper.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class SwitcherWidgetIndex : uint8
{
	MainMenuWidget,
	ServerBrowserWidget,
	HostServerWidget
};

UCLASS(Abstract)
class GSMENUMODULE_API UGSMainMenuWidgetWrapper : public UGSUserWidgetBase
{
	GENERATED_BODY()
	
	protected:
	virtual void NativeOnInitialized() override;
	
	public:
	UPROPERTY(meta=(BindWidget))
	class UWidgetSwitcher* MainMenuWidgetSwitcher;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UGSMainMenuWidget> MainMenuWidgetClass;
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UGSServerBrowserWidget> ServerBrowserWidgetClass;
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UGSHostServerWidget> HostServerWidgetClass;

	UPROPERTY(meta=(BindWidget))
	UGSMainMenuWidget* MainMenuWidget;
	UPROPERTY(meta=(BindWidget))
	UGSServerBrowserWidget* ServerBrowserWidget;
	UPROPERTY(meta=(BindWidget))
	UGSHostServerWidget* HostServerWidget;

	public:
	UFUNCTION(BlueprintCallable)
	void SwitchWidget(UWidgetSwitcher* Widget, UGSUserWidgetBase* Index);
	
	private:
	void BindDelegates();
};
