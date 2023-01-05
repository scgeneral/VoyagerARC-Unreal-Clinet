// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Engine/DataTable.h"
#include "Materials/MaterialInstance.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyCoreTypes.generated.h"

USTRUCT(BlueprintType)
struct FSendData
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FTransform transform;
};

USTRUCT(BlueprintType)
struct FFurnitureMaterial
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSoftObjectPtr<UTexture2D> Icon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSoftObjectPtr<UMaterialInstance> MaterialInstance;
};

USTRUCT(Blueprintable)
struct FFurnitureData : public FTableRowBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSoftObjectPtr<UStaticMesh> Mesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FFurnitureMaterial FurnitureMaterial;
};


