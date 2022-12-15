// Fill out your copyright notice in the Description page of Project Settings.


#include "VoyagerARSceneActor.h"

#include "Components/StaticMeshComponent.h"

// Sets default values
AVoyagerARSceneActor::AVoyagerARSceneActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SceneComponent = CreateDefaultSubobject<USceneComponent>("Root");
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	WidgetComponent = CreateDefaultSubobject<UWidgetComponent>("InteractWidget");

	WidgetComponent->SetVisibility(false);
	RootComponent = SceneComponent;
}

// Called when the game starts or when spawned
void AVoyagerARSceneActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVoyagerARSceneActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool AVoyagerARSceneActor::bCanChangeLocation() const
{
	return true;
}

bool AVoyagerARSceneActor::bCanChangeScale() const
{
	return true;
}

bool AVoyagerARSceneActor::bCanChangeRotation() const
{
	return true;
}

bool AVoyagerARSceneActor::bCanChangeColor() const
{
	return false;
}

bool AVoyagerARSceneActor::bActorWorkingWithNFT() const
{
	return false;
}

void AVoyagerARSceneActor::SetSceneActorLocation(const FVector& Location)
{
	SetActorLocation(Location);
}

void AVoyagerARSceneActor::SetSceneActorScale(const FVector& Scale)
{
	SetActorScale3D(Scale);
}

void AVoyagerARSceneActor::SetSceneActorRotation(const FRotator& Rotation)
{
	SetActorRotation(Rotation);
}

void AVoyagerARSceneActor::SetNFTTexture(UTexture2D* Texture)
{
}

void AVoyagerARSceneActor::SetColor(const FVector& Color)
{
	
}

void AVoyagerARSceneActor::ShowInteractionWidget()
{
	WidgetComponent->SetVisibility(true);
}

void AVoyagerARSceneActor::HideInteractionWidget()
{
	WidgetComponent->SetVisibility(false);
}

void AVoyagerARSceneActor::OnStartInteract()
{
}

void AVoyagerARSceneActor::OnEndInteract()
{
}

bool AVoyagerARSceneActor::CheckCanObjectBeDropped()
{
	return false;
}

void AVoyagerARSceneActor::SetIsObjectAttached(bool isObjectAttached)
{
}

TArray<FName> AVoyagerARSceneActor::GetAvaliableAttachTags()
{
	return TArray<FName>();
}

