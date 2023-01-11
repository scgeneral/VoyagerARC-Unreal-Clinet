// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyCoreTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine/StreamableRenderAsset.h"
#include "VoyageARFunctionLibrary.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_DELEGATE_TwoParams(FAsyncLoadRenderComponentDelegate, const TArray<UStreamableRenderAsset*>&, NewMeshes, FName, SocketName);
//DECLARE_DYNAMIC_DELEGATE_TwoParams(FMyAsyncActorDelegate, UObject*, ResultObject, TSoftObjectPtr<UStreamableRenderAsset>&, AssetPtr);
//DECLARE_DELEGATE_OneParam(FMyAsyncActorDelegate, UObject*);

UCLASS()
class VOYAGEAR_API UVoyageARFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	void AsyncLoadRenderComponentComplete(UObject* WorldContextObject,TArray<TSoftObjectPtr<UStreamableRenderAsset>> Assets, TArray<FStringAssetReference> References, const FAsyncLoadRenderComponentDelegate Callback, FName Name)
	
	UFUNCTION(BlueprintCallable)
	void AsyncDownloadActor(UObject* WorldContextObject, const TSoftObjectPtr<UStreamableRenderAsset>& AssetPtr, const FMyAsyncActorDelegate& Callback);

	void AsyncLoadRenderComponent(UObject* WorldContextObject, const TArray<TSoftObjectPtr<UStreamableRenderAsset>>& Assets, const FAsyncLoadRenderComponentDelegate& Callback, FName Name)
	
	void OnAsyncDownloadActorComplete(UObject* WorldContextObject, FStringAssetReference Reference,const FMyAsyncActorDelegate Callback);
};
