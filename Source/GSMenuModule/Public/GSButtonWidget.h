// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GSUserWidgetBase.h"
#include "GSButtonWidget.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class GSMENUMODULE_API UGSButtonWidget : public UGSUserWidgetBase
{
	GENERATED_BODY()
	protected:
	virtual void NativeConstruct() override;
	virtual void NativeOnInitialized() override;
	
	public:
	virtual void SynchronizeProperties() override;

	public:
	UPROPERTY(meta=(BindWidget))
	class UTextBlock* TextBlockElement;
	UPROPERTY(meta=(BindWidget))
	class UButton* ButtonElement;

	UPROPERTY(EditAnywhere, Category="GS|Text")
	FText ButtonTextContent;
	
};
