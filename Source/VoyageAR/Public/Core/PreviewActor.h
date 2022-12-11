// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UserWidget.h"
#include "WidgetComponent.h"
#include "GameFramework/Actor.h"
#include "Materials/MaterialInstance.h"
#include "PreviewActor.generated.h"

UENUM(BlueprintType)
enum MeshType
{
	EFurniture = 0 UMETA(DisplayName = "Furniture"),
	EPicture = 1 UMETA(DisplayName = "Picture"),
};

USTRUCT(BlueprintType)
struct FMeshInfo
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	TEnumAsByte<MeshType> MeshType;
};

UCLASS()
class VOYAGEAR_API APreviewActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APreviewActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Mesh;

	UFUNCTION(BlueprintCallable)
	void InitPreviewMeshMetaData(FMeshInfo MeshMetaData);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UMaterialInstance* BlackoutMaterial;

	virtual void CheckPreviewActorOverlapCorrectPlane(const FString& CorrectActorTag);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void ShowInteractionAction();

	virtual void ShowInteractionAction_Implementation();
	
	virtual void SetPreviewActorLocation(const FHitResult& HitResult);
	virtual void SetPreviewActorRotation(float DeltaRotation);
	virtual void SetPreviewActorScale(float DeltaScale);
protected:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UWidgetComponent* WidgetComponent;

	FMeshInfo CurrentMeshMetaData;

	UFUNCTION()
	void HandlePreviewActorOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:

	UPROPERTY()
	UMaterialInstanceDynamic* DynamicMaterial;

	bool bNowOverlapWrongCollision;

	FString CheckPlaneTag = "floor";
};
