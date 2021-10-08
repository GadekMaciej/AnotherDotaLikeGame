// Fill out your copyright notice in the Description page of Project Settings.


#include "GS_LobbyLevelCharacter.h"

// Sets default values
AGS_LobbyLevelCharacter::AGS_LobbyLevelCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGS_LobbyLevelCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGS_LobbyLevelCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGS_LobbyLevelCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

