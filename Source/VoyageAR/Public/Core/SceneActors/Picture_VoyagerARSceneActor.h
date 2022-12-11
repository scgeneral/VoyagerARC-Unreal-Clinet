// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/VoyagerARSceneActor.h"
#include "Picture_VoyagerARSceneActor.generated.h"

/**
 * 
 */
UCLASS()
class VOYAGEAR_API APicture_VoyagerARSceneActor : public AVoyagerARSceneActor
{
	GENERATED_BODY()

public:
	APicture_VoyagerARSceneActor();
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<UTexture2D*> AvailableTextures;

public:
	UFUNCTION(BlueprintCallable)
	TArray<UTexture2D*> GetAvailableTexturesForObject();
};
