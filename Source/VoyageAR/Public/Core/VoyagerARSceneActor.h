// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PreviewActor.h"
#include "WidgetComponent.h"
#include "GameFramework/Actor.h"
#include "VoyagerARSceneActor.generated.h"

UCLASS()
class VOYAGEAR_API AVoyagerARSceneActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVoyagerARSceneActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Mesh;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly)
	USceneComponent* SceneComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UWidgetComponent* WidgetComponent;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual bool bCanChangeLocation() const;
	virtual bool bCanChangeScale() const;
	virtual bool bCanChangeRotation() const;
	virtual bool bCanChangeColor() const;
	virtual bool bActorWorkingWithNFT() const;
	virtual void SetSceneActorLocation(const FVector& Location);
	virtual void SetSceneActorScale(const FVector& Scale);
	virtual void SetSceneActorRotation(const FRotator& Rotation);
	virtual void SetNFTTexture(UTexture2D* Texture);
	virtual void SetColor(const FVector& Color);

	void ShowInteractionWidget();
	void HideInteractionWidget();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TEnumAsByte<MeshType> ActorType = MeshType::EFurniture;
};
