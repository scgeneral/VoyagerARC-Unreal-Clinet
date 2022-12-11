// Fill out your copyright notice in the Description page of Project Settings.


#include "VoyageARGameModeBase.h"

#include "FileHelper.h"
#include "Paths.h"
#include "TimerManager.h"
#include "Engine/Engine.h"
#include "Engine/World.h"

void AVoyageARGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Display, TEXT("AVoyageARGameModeBase::BeginPlay Launch"));
	GetWorld()->GetTimerManager().SetTimer(TestWriteFileTimerHandle, this, &AVoyageARGameModeBase::Test_WriteToFile, 5.0f, false);
	GetWorld()->GetTimerManager().SetTimer(TestReadFileTimerHandle, this, &AVoyageARGameModeBase::Test_ReadFromFile, 10.0f, false);
}

void AVoyageARGameModeBase::Test_WriteToFile()
{
	FString SaveDirectory = FPaths::ProjectSavedDir();
	SaveDirectory += "Test.json";

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Test file path: %s"), *SaveDirectory));
	UE_LOG(LogTemp, Display, TEXT("Test file path: %s"), *SaveDirectory);
	const FString TestString = "Test string saving to local storage";
	
	FFileHelper::SaveStringToFile(TestString, *SaveDirectory);
}

void AVoyageARGameModeBase::Test_ReadFromFile()
{
	FString SaveDirectory = FPaths::ProjectSavedDir();
	SaveDirectory += "Test.json";
   	
	FString FileString;
	FFileHelper::LoadFileToString(FileString, *SaveDirectory);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("File string: %s"), *FileString));
	UE_LOG(LogTemp, Display, TEXT("File string: %s"), *FileString);
}
