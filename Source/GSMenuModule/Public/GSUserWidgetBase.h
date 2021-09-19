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

	// deprecated
	// UFUNCTION(BlueprintCallable)
	// void NavigateToWidget(TSubclassOf<UGSUserWidgetBase> NewWidget);
};
