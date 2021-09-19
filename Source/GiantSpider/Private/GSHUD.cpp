// Fill out your copyright notice in the Description page of Project Settings.


#include "GSHUD.h"

#include "GSMainMenuWidgetWrapper.h"
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
		MainMenuWidget = CreateWidget<UGSMainMenuWidgetWrapper>(UGameplayStatics::GetPlayerController(GetWorld(), 0), MainMenuWidgetClass,"MainMenuWidget");

	}
	if(MainMenuWidget)
	{
		APlayerController* PC = GetOwningPlayerController();
		PC->SetInputMode(FInputModeUIOnly());
		PC->SetShowMouseCursor(true);
		ShowMainMenu(MainMenuWidget);
	}
}

void AGSHUD::ShowMainMenu(UGSMainMenuWidgetWrapper* MMW)
{
	MMW->AddToViewport();
}
