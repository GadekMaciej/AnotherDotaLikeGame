// Fill out your copyright notice in the Description page of Project Settings.


#include "GS_LobbyLevelCharacter.h"

#define WORLD_FORWARD_VECTOR FVector(1, 0, 0)
#define WORLD_RIGHT_VECTOR FVector(0, 1, 0)
#define WORLD_UP_VECTOR FVector(0, 0, 1)



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
	check(PlayerInputComponent);
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &ThisClass::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ThisClass::MoveRight);
	
}

void AGS_LobbyLevelCharacter::MoveForward(float Value)
{
	if (Controller && Value != 0)
	{
		AddMovementInput(WORLD_FORWARD_VECTOR, Value);
	}
}

void AGS_LobbyLevelCharacter::MoveRight(float Value)
{
	if (Controller && Value != 0)
	{
		AddMovementInput(WORLD_RIGHT_VECTOR, Value);
	}
}

