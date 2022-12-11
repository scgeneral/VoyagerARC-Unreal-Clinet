// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "VoyageARGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class VOYAGEAR_API AVoyageARGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
public:
	void Test_WriteToFile();

	void Test_ReadFromFile();
private:
	FTimerHandle TestWriteFileTimerHandle;

	FTimerHandle TestReadFileTimerHandle;
};
