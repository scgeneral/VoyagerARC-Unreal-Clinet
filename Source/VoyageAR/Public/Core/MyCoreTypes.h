// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "MyCoreTypes.generated.h"

USTRUCT(BlueprintType)
struct FSendData
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FTransform transform;
};
