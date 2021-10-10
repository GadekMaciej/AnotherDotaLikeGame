// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "GS_LobbyLevelScriptActor.generated.h"

/**
 * 
 */
UCLASS()
class GIANTSPIDER_API AGS_LobbyLevelScriptActor : public ALevelScriptActor
{
	GENERATED_BODY()
	
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, NoClear)
	ACameraActor* ArenaCamera;
};
