// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GSUserWidgetBase.h"
#include "GSHostServerWidget.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class GSMENUMODULE_API UGSHostServerWidget : public UGSUserWidgetBase
{
	GENERATED_BODY()
	protected:
	virtual void NativeOnInitialized() override;
	
	public:
	UPROPERTY(meta=(BindWidget))
	class UGSButtonWidget* BackButton;
	
	UPROPERTY(meta=(BindWidget))
	UGSButtonWidget* HostButton;

	UPROPERTY(meta=(BindWidget))
	class UEditableTextBox* ServerNameEditText;

	UPROPERTY(EditDefaultsOnly, Category="GS|Navigation")
	TSubclassOf<UGSUserWidgetBase> ServerBrowserClass;
	
	public:
	UFUNCTION()
	void OnBackButtonClicked();
	
	UFUNCTION()
	void OnHostButtonClicked();

	UFUNCTION()
	void OnSessionCreated(FName SessionName, bool bWasSuccessful);
};
