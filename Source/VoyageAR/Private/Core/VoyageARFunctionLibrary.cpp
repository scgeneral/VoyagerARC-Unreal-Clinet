// Fill out your copyright notice in the Description page of Project Settings.

#include "VoyageARFunctionLibrary.h"
#include "CoreMinimal.h"
#include "VoyageARGameGlobals.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine/StreamableManager.h"


void UVoyageARFunctionLibrary::AsyncDownloadActor(UObject* WorldContextObject, const TSoftObjectPtr<UStreamableRenderAsset>& AssetPtr, const FMyAsyncActorDelegate& Callback)
{
    // ���������� ��������� ����� � ������
    FStreamableManager& AssetLoader = UVoyageARGameGlobals::Get().AssetLoader;
    FStringAssetReference Reference = AssetPtr.ToStringReference();
    
    AssetLoader.RequestAsyncLoad(Reference, FStreamableDelegate::CreateStatic(&UVoyageARFunctionLibrary::OnAsyncDownloadActorComplete, WorldContextObject, Reference, Callback));
}

void UVoyageARFunctionLibrary::OnAsyncDownloadActorComplete(UObject* WorldContextObject, FStringAssetReference Reference, const FMyAsyncActorDelegate Callback)
{
    //  ����� ������ ������ ���� � ������, �������� ��������� ������ ������
    UStreamableRenderAsset* ActorClass = Cast<UStreamableRenderAsset>(StaticLoadObject(UStreamableRenderAsset::StaticClass(), nullptr, *(Reference.ToString())));
    // �������� ������� � ������ � ���������
    Callback.ExecuteIfBound(ActorClass);
}

void UVoyageARFunctionLibrary::AsyncLoadRenderComponent(UObject* WorldContextObject, const TArray<TSoftObjectPtr<UStreamableRenderAsset>>& Assets, const FAsyncLoadRenderComponentDelegate& Callback, FName Name)
{
    FStreamableManager& AssetLoader = UVoyageARGameGlobals::Get().AssetLoader;

    TArray<FStringAssetReference> ReferenceList;

    for (auto& Asset : Assets)
    {
        ReferenceList.Add(Asset.ToSoftObjectPath());	
    }

    auto AsyncLoadRenderComponentCompleteLambda = [](UObject* WorldContextObject,TArray<TSoftObjectPtr<UStreamableRenderAsset>> Assets, TArray<FStringAssetReference> References, const FAsyncLoadRenderComponentDelegate Callback, FName Name)
    {
        TArray<UStreamableRenderAsset*> AssetList;
	
        for (auto& AssetPtr : Assets)
        {
            UStreamableRenderAsset* Asset = AssetPtr.Get();
            if (!Asset) return;
            AssetList.Add(Asset);
        }
        Callback.ExecuteIfBound(AssetList, Name);
    };
    
    AssetLoader.RequestAsyncLoad(ReferenceList, FStreamableDelegate::CreateStatic(AsyncLoadRenderComponentCompleteLambda, WorldContextObject, Assets, ReferenceList, Callback, Name));
}

void UVoyageARFunctionLibrary::AsyncLoadRenderComponentComplete(UObject* WorldContextObject,TArray<TSoftObjectPtr<UStreamableRenderAsset>> Assets, TArray<FStringAssetReference> References, const FAsyncLoadRenderComponentDelegate Callback, FName Name)
{
   
}