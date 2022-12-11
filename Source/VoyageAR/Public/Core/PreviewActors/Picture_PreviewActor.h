// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/PreviewActor.h"
#include "Picture_PreviewActor.generated.h"

/**
 * 
 */
UCLASS()
class VOYAGEAR_API APicture_PreviewActor : public APreviewActor
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	
public:
	APicture_PreviewActor();
	virtual void ShowInteractionAction_Implementation() override;
	
	virtual void SetPreviewActorLocation(const FHitResult& HitResult) override;
};
