// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "GSMainMenuLevelScriptActor.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class GIANTSPIDER_API AGSMainMenuLevelScriptActor : public ALevelScriptActor
{
	GENERATED_BODY()
	
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, NoClear)
	ACameraActor* MainMenuCamera;
	
};
