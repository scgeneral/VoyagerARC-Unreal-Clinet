// Fill out your copyright notice in the Description page of Project Settings.


#include "VoyageARGameGlobals.h"
#include "EngineMinimal.h"
#include "Engine.h"

UVoyageARGameGlobals& UVoyageARGameGlobals::Get() 
{
	UVoyageARGameGlobals* Singleton = Cast<UVoyageARGameGlobals>(GEngine->GameSingleton);

	if (Singleton)
	{
		return *Singleton;
	}
	else 
	{
		return *NewObject<UVoyageARGameGlobals>(UVoyageARGameGlobals::StaticClass());
	}
}