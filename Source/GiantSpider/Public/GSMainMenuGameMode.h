// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "GSMainMenuGameMode.generated.h"

/**
 * 
 */
UCLASS()
class GIANTSPIDER_API AGSMainMenuGameMode : public AGameMode
{
	GENERATED_BODY()

	virtual void StartPlay() override;
	
};
