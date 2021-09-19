// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GSHUD.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class GIANTSPIDER_API AGSHUD : public AHUD
{
	GENERATED_BODY()
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UGSMainMenuWidgetWrapper> MainMenuWidgetClass;
	UPROPERTY()
	UGSMainMenuWidgetWrapper* MainMenuWidget;

	UFUNCTION(BlueprintCallable)
	void CreateMainMenuWidget();
	UFUNCTION(BlueprintCallable)
	void ShowMainMenu(UGSMainMenuWidgetWrapper* MMW);
	
};
