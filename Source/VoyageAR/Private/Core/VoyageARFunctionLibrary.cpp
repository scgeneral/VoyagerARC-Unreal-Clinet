// Fill out your copyright notice in the Description page of Project Settings.

#include "VoyageARFunctionLibrary.h"
#include "CoreMinimal.h"
#include "VoyageARGameGlobals.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine/StreamableManager.h"


void UVoyageARFunctionLibrary::AsyncDownloadActor(UObject* WorldContextObject, const TSoftObjectPtr<UStreamableRenderAsset>& AssetPtr, const FMyAsyncActorDelegate& Callback)
{
    // Асинхронно загружаем ассет в память
    FStreamableManager& AssetLoader = UVoyageARGameGlobals::Get().AssetLoader;
    FStringAssetReference Reference = AssetPtr.ToStringReference();
    
    //AssetLoader.RequestAsyncLoad(Reference, FStreamableDelegate::CreateStatic(&UVoyageARFunctionLibrary::OnAsyncDownloadActorComplete, WorldContextObject, Reference, Callback));
}

void UVoyageARFunctionLibrary::OnAsyncDownloadActorComplete(UObject* WorldContextObject, FStringAssetReference Reference,const FMyAsyncActorDelegate Callback)
{
    //  Ассет теперь должен быть в памяти, пытаемся загрузить объект класса
    UStreamableRenderAsset* ActorClass = Cast<UStreamableRenderAsset>(StaticLoadObject(UStreamableRenderAsset::StaticClass(), nullptr, *(Reference.ToString())));
    // Вызываем событие о спавне в блюпринты
    Callback.ExecuteIfBound(ActorClass);
}
