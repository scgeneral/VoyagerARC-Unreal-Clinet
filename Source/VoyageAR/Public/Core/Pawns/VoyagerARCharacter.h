// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "VoyagerARCharacter.generated.h"

UCLASS()
class VOYAGEAR_API AVoyagerARCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AVoyagerARCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void HandleRotationAxis(float Value);

	UFUNCTION(BlueprintNativeEvent)
	void BP_HandleRotationAxis(float Value);

	void HandleScaleAxis(float Value);

	UFUNCTION(BlueprintNativeEvent)
	void BP_HandleScaleAxis(float Value);
	
	virtual void BP_HandleRotationAxis_Implementation(float Value);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	void InteractChangePicture();
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Interact();

	UFUNCTION(BlueprintNativeEvent)
	void BP_Interact();

	virtual void BP_Interact_Implementation();

	UFUNCTION(BlueprintNativeEvent)
	void BP_InteractChangeTexture();

	virtual void BP_InteractChangeTexture_Implementation();
};
