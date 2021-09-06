// Fill out your copyright notice in the Description page of Project Settings.


#include "GSMainMenuLevelScriptActor.h"

#include "GSHUD.h"
#include "Kismet/GameplayStatics.h"

void AGSMainMenuLevelScriptActor::BeginPlay()
{
	Super::BeginPlay();
	APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if(PC)
	{
		AGSHUD* PlayerHud = Cast<AGSHUD>(PC->GetHUD());
		if(PlayerHud)
		{
			PlayerHud->CreateMainMenuWidget();
		}
	}
}
