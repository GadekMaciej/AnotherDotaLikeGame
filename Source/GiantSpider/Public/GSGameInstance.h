// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "GSGameInstance.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class GIANTSPIDER_API UGSGameInstance : public UGameInstance
{
	GENERATED_BODY()

	public:
	virtual void Init() override;
	// test function for checking if session was created
	UFUNCTION()
	void OnPlayerSessionCreated(bool bIsSuccessful);

	void OnPlayerSessionJoined(EOnJoinSessionCompleteResult::Type Result);
};
