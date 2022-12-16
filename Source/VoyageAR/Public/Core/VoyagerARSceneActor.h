// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PreviewActor.h"
#include "WidgetComponent.h"
#include "GameFramework/Actor.h"
#include "Interface/IInteractableObject.h"
#include "VoyagerARSceneActor.generated.h"

USTRUCT(BlueprintType)
struct FSendData
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTransform transform;
};

UCLASS()
class VOYAGEAR_API AVoyagerARSceneActor : public AActor, public IIInteractableObject
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVoyagerARSceneActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FSendData sendData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction Variables")
	TArray<FName> CanAttachTagsArray;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Interaction Variables")
	bool IsObjectAttach;
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

	// from interface

	//UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
	void OnStartInteract();
	void OnEndInteract();
	bool CheckCanObjectBeDropped();
	void SetIsObjectAttached(bool isObjectAttached);
	TArray<FName> GetAvaliableAttachTags();
	void OnActivateOutline();
	//

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TEnumAsByte<MeshType> ActorType = MeshType::EFurniture;
};
