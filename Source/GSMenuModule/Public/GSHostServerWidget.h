// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GSUserWidgetBase.h"
#include "GSHostServerWidget.generated.h"

/**
 * 
 */

DECLARE_DELEGATE(FOnBackButtonClicked)
DECLARE_DELEGATE(FOnHostButtonClicked)

UCLASS(Abstract)
class GSMENUMODULE_API UGSHostServerWidget : public UGSUserWidgetBase
{
	GENERATED_BODY()
	protected:
	virtual void NativeOnInitialized() override;
	
	public:
	FOnBackButtonClicked FOnBackButtonClickedEvent;
	FOnHostButtonClicked FOnHostButtonClickedEvent;
	
	UPROPERTY(meta=(BindWidget))
	class UEditableTextBox* ServerNameEditText;

	protected:

	private:
	UPROPERTY(meta=(BindWidget))
	class UGSButtonWidget* BackButton;
	UPROPERTY(meta=(BindWidget))
	UGSButtonWidget* HostButton;
	
	public:
	
	protected:
	UFUNCTION(BlueprintCallable)
	void OnBackButtonClicked();
	UFUNCTION(BlueprintCallable)
	void OnHostButtonClicked();
	
	private:

};
