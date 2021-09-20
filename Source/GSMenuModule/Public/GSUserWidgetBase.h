// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GSUserWidgetBase.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class GSMENUMODULE_API UGSUserWidgetBase : public UUserWidget
{
	GENERATED_BODY()
	public:
	virtual void SynchronizeProperties() override;

	// logic that runs optionally after this widget is being swiched onto 
	UFUNCTION(BlueprintCallable)
	virtual void OnSwitch();
	// deprecated
	// UFUNCTION(BlueprintCallable)
	// void NavigateToWidget(TSubclassOf<UGSUserWidgetBase> NewWidget);
};
