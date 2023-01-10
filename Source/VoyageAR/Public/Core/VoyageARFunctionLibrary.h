// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine/StreamableRenderAsset.h"
#include "VoyageARFunctionLibrary.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_DELEGATE_OneParam(FMyAsyncActorDelegate, UStreamableRenderAsset*, ResultObject);
//DECLARE_DYNAMIC_DELEGATE_TwoParams(FMyAsyncActorDelegate, UObject*, ResultObject, TSoftObjectPtr<UStreamableRenderAsset>&, AssetPtr);
//DECLARE_DELEGATE_OneParam(FMyAsyncActorDelegate, UObject*);

UCLASS()
class VOYAGEAR_API UVoyageARFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
		void AsyncDownloadActor(UObject* WorldContextObject, const TSoftObjectPtr<UStreamableRenderAsset>& AssetPtr, const FMyAsyncActorDelegate& Callback);

		void OnAsyncDownloadActorComplete(UObject* WorldContextObject, FStringAssetReference Reference,const FMyAsyncActorDelegate Callback);
};
