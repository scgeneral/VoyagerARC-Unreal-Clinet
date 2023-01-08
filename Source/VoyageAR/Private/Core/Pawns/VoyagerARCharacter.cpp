// Fill out your copyright notice in the Description page of Project Settings.

#include "VoyageAR/Public/Core/Pawns/VoyagerARCharacter.h"

#include "Components/InputComponent.h"

// Sets default values
AVoyagerARCharacter::AVoyagerARCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AVoyagerARCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AVoyagerARCharacter::HandleRotationAxis(float Value)
{
	BP_HandleRotationAxis(Value);
}

void AVoyagerARCharacter::HandleScaleAxis(float Value)
{
	BP_HandleScaleAxis(Value);
}

void AVoyagerARCharacter::BP_HandleScaleAxis_Implementation(float Value)
{
}

void AVoyagerARCharacter::BP_HandleRotationAxis_Implementation(float Value)
{
}

// Called every frame
void AVoyagerARCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AVoyagerARCharacter::InteractChangePicture()
{
	BP_InteractChangeTexture();
}

// Called to bind functionality to input
void AVoyagerARCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAction("InteractionAction", IE_Pressed, this, &AVoyagerARCharacter::Interact);

	//TODO remove it from here or replace logic from blueprint input binding here in C++
	//InputComponent->BindAction("InteractionChangeTexture", IE_Pressed, this, &AVoyagerARCharacter::InteractChangePicture);
	
	//InteractionChangeTexture
	InputComponent->BindAxis("RotateObject", this, &AVoyagerARCharacter::HandleRotationAxis);
	InputComponent->BindAxis("ScaleObject", this, &AVoyagerARCharacter::HandleScaleAxis);
}

void AVoyagerARCharacter::Interact()
{
	BP_Interact();
}

void AVoyagerARCharacter::BP_Interact_Implementation()
{
}

void AVoyagerARCharacter::BP_InteractChangeTexture_Implementation()
{
}

