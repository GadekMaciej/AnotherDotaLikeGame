// Fill out your copyright notice in the Description page of Project Settings.


#include "GSHUD.h"

#include "GSMainMenuWidget.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

void AGSHUD::BeginPlay()
{
	Super::BeginPlay();
}

void AGSHUD::CreateMainMenuWidget()
{
	if(IsValid(MainMenuWidgetClass) && !MainMenuWidget)
	{
		MainMenuWidget = CreateWidget<UGSMainMenuWidget>(UGameplayStatics::GetPlayerController(GetWorld(), 0), MainMenuWidgetClass,"MainMenuWidget");

	}
	if(MainMenuWidget)
	{
		ShowMainMenu();
	}
}

void AGSHUD::ShowMainMenu()
{
	MainMenuWidget->AddToViewport();
}
