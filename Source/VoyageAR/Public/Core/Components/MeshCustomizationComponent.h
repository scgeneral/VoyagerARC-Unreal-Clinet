// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PreviewActor.h"
#include "VoyagerARSceneActor.h"
#include "Components/ActorComponent.h"
#include "Materials/MaterialInstance.h"
#include "MeshCustomizationComponent.generated.h"

USTRUCT(BlueprintType)
struct FAvailableCustomizationParams
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	bool bCanChangeLocation = false;

	UPROPERTY(BlueprintReadWrite)
	bool bCanChangeRotation = false;

	UPROPERTY(BlueprintReadWrite)
	bool bCanChangeScale = false;

	UPROPERTY(BlueprintReadWrite)
	bool bCanChangeColor = false;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VOYAGEAR_API UMeshCustomizationComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMeshCustomizationComponent();

	UFUNCTION(BlueprintCallable)
	void StartCustomizationProcess();
	
	UFUNCTION(BlueprintCallable)
	void EndCustomizationProcess();

	UFUNCTION(BlueprintCallable)
	void StartSetTextureProcess();
	UFUNCTION(BlueprintCallable)
	void EndSetTextureProcess();

	UFUNCTION(BlueprintCallable)
	TArray<UTexture2D*> GetAvailableTexturesForObject();

	UFUNCTION(BlueprintCallable)
	void SetTextureForObject(UTexture2D* Texture);
	
	UFUNCTION(BlueprintCallable)
	void GetAvailableCustomizationParams(FAvailableCustomizationParams& Params);

	UFUNCTION(BlueprintCallable)
	void ProcessPreviewActorRotation(float Value);

	UFUNCTION(BlueprintCallable)
	void ProcessPreviewActorScale(float Value);
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY()
	APreviewActor* PreviewActor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<APreviewActor> PreviewActorClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TMap<TEnumAsByte<MeshType>, TSubclassOf<APreviewActor>> PreviewActorMap;
		
	UFUNCTION()
	void ProcessLocationChange();
public:	

	UFUNCTION(BlueprintCallable)
	void ShowInteractionWidget(AVoyagerARSceneActor* NewFocusActor);
	UFUNCTION(BlueprintCallable)
	void HideInteractionWidget();
	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
private:
	UPROPERTY()
	AVoyagerARSceneActor* FocusActor;

	UPROPERTY()
	AVoyagerARSceneActor* BufferedActor;

	bool bCustomizationProcessStarted;
};
