// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/StreamableManager.h"
#include "VoyageARGameGlobals.generated.h"

/**
 * 
 */
UCLASS()
class VOYAGEAR_API UVoyageARGameGlobals : public UObject
{
	GENERATED_BODY()
public:
	static UVoyageARGameGlobals& Get();
	FStreamableManager AssetLoader;
};
