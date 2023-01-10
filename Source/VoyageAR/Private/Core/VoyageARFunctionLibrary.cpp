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
    
    //AssetLoader.RequestAsyncLoad(Reference, FStreamableDelegate::CreateStatic(&UVoyageARFunctionLibrary::OnAsyncDownloadActorComplete, WorldContextObject, Reference, Callback));
}

void UVoyageARFunctionLibrary::OnAsyncDownloadActorComplete(UObject* WorldContextObject, FStringAssetReference Reference,const FMyAsyncActorDelegate Callback)
{
    //  ����� ������ ������ ���� � ������, �������� ��������� ������ ������
    UStreamableRenderAsset* ActorClass = Cast<UStreamableRenderAsset>(StaticLoadObject(UStreamableRenderAsset::StaticClass(), nullptr, *(Reference.ToString())));
    // �������� ������� � ������ � ���������
    Callback.ExecuteIfBound(ActorClass);
}
