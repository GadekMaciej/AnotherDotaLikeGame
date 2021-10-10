// Fill out your copyright notice in the Description page of Project Settings.


#include "GS_LobbyLevelScriptActor.h"

#include "Kismet/GameplayStatics.h"
#include "Camera/CameraActor.h"

void AGS_LobbyLevelScriptActor::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	
	if(PC)
	{
		PC->SetViewTarget(ArenaCamera);
	}
}
