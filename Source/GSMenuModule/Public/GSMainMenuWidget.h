// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GSUserWidgetBase.h"
#include "GSMainMenuWidget.generated.h"

/**
 * 
 */

DECLARE_DELEGATE(OnMultiplayerButtonClicked)
DECLARE_DELEGATE(OnQuitButtonClicked)

UCLASS(Abstract)
class GSMENUMODULE_API UGSMainMenuWidget : public UGSUserWidgetBase
{
	GENERATED_BODY()
	
	public:
	virtual void SynchronizeProperties() override;
	
	protected:
	virtual void NativeConstruct() override;
	virtual void NativeOnInitialized() override;

	private:
	
	public:
	OnMultiplayerButtonClicked OnMultiplayerButtonClickedEvent;
	OnQuitButtonClicked OnQuitButtonClickedEvent;

	UPROPERTY(EditAnywhere, Category="GS|Text")
	FText TitleText;
	
	protected:
	
	private:
	UPROPERTY(meta=(BindWidget))
	class UGSButtonWidget* SingleplayerButton;
	
	UPROPERTY(meta=(BindWidget))
	UGSButtonWidget* MultiplayerButton;
	
	UPROPERTY(meta=(BindWidget))
	UGSButtonWidget* QuitButton;
	
	UPROPERTY(meta=(BindWidget))
	class UTextBlock* TitleTextBlock;

	public:
	
	protected:
	UFUNCTION(BlueprintCallable)
	void OnQuitButtonClicked();

	UFUNCTION(BlueprintCallable)
	void OnMultiplayerButtonClicked();
	
	private:
};
