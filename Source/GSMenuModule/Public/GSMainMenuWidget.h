// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GSUserWidgetBase.h"
#include "GSMainMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class GSMENUMODULE_API UGSMainMenuWidget : public UGSUserWidgetBase
{
	GENERATED_BODY()
	
	protected:
	virtual void NativeConstruct() override;
	virtual void NativeOnInitialized() override;
	
	public:
	virtual void SynchronizeProperties() override;

	public:
	UPROPERTY(meta=(BindWidget))
	class UGSButtonWidget* SingleplayerButton;
	UPROPERTY(meta=(BindWidget))
	UGSButtonWidget* MultiplayerButton;
	UPROPERTY(meta=(BindWidget))
	UGSButtonWidget* QuitButton;
	UPROPERTY(meta=(BindWidget))
	class UTextBlock* TitleTextBlock;

	UPROPERTY(EditAnywhere, Category="GS|Text")
	FText TitleText;
	
};
