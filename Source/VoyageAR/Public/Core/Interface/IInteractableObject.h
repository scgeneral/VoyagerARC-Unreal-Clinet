// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IInteractableObject.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIInteractableObject : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class VOYAGEAR_API IIInteractableObject
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
	void OnStartInteract();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
	void OnEndInteract();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
	bool CheckCanObjectBeDropped();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
	void SetIsObjectAttached(bool isObjectAttached);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
	TArray<FName> GetAvaliableAttachTags();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
	void OnActivateOutline();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
	bool CheckCanObjectChangeTexture();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
	TArray<UTexture2D*> GetAvaliableTextures();
};
