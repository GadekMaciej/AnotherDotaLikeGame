// Fill out your copyright notice in the Description page of Project Settings.


#include "GSHUD.h"
#include "Modules/ModuleManager.h"
void AGSHUD::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("HUD loaded") );
	bool ModuleStatus = FModuleManager::Get().IsModuleLoaded("GSMenuModule");
	if(ModuleStatus)
	{
		UE_LOG(LogTemp, Warning, TEXT("Some warning message") );
	}
}
