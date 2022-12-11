// Fill out your copyright notice in the Description page of Project Settings.


#include "MeshCustomizationComponent.h"

#include "Picture_VoyagerARSceneActor.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Materials/MaterialInstanceDynamic.h"

// Sets default values for this component's properties
UMeshCustomizationComponent::UMeshCustomizationComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UMeshCustomizationComponent::StartCustomizationProcess()
{
	//BufferedActor = Actor;
	if (FocusActor)
	{
		UE_LOG(LogTemp, Display, TEXT("UMeshCustomizationComponent::StartCustomizationProcess focus actor location %f, %f, %f"), FocusActor->GetActorLocation().X,FocusActor->GetActorLocation().Y, FocusActor->GetActorLocation().Z);
		const FTransform Transforms = FocusActor->GetActorTransform();
		
		auto CreatedPreviewActor = GetWorld()->SpawnActorDeferred<APreviewActor>(PreviewActorMap[FocusActor->ActorType], Transforms);
		PreviewActor = CreatedPreviewActor;
		PreviewActor->Mesh->SetStaticMesh(FocusActor->Mesh->GetStaticMesh());

		bCustomizationProcessStarted = true;
		//PreviewActor->InitPreviewMeshMetaData()
		BufferedActor = FocusActor;
		
		UGameplayStatics::FinishSpawningActor(PreviewActor, Transforms);
		BufferedActor->SetActorLocation(FVector(100000.0f), false);
	}
}

void UMeshCustomizationComponent::EndCustomizationProcess()
{
	if (PreviewActor)
	{
		const auto FinalTransform = PreviewActor->GetActorTransform();
	
		BufferedActor->SetSceneActorLocation(FinalTransform.GetLocation());
		BufferedActor->SetSceneActorRotation(FinalTransform.GetRotation().Rotator());
		BufferedActor->SetSceneActorScale(FinalTransform.GetScale3D());
		BufferedActor = nullptr;
		bCustomizationProcessStarted = false;
	
		UE_LOG(LogTemp, Display, TEXT("UMeshCustomizationComponent::EndCustomizationProcess focus actor location %f, %f, %f"), FinalTransform.GetLocation().X,FinalTransform.GetLocation().Y, FinalTransform.GetLocation().Z);
		PreviewActor->Destroy();
	}
}

void UMeshCustomizationComponent::StartSetTextureProcess()
{
	auto Character = Cast<ACharacter>(GetOwner());
	if (Character)
	{
		BufferedActor = FocusActor;
		auto CharacterMovement = Character->GetCharacterMovement();
		CharacterMovement->DisableMovement();

		auto Controller = Character->GetController();

		if (Controller)
		{
			auto PC = Cast<APlayerController>(Controller);
			PC->bShowMouseCursor = true;

			//PC->DisableInput()
		}
	}
}

void UMeshCustomizationComponent::EndSetTextureProcess()
{
	auto Character = Cast<ACharacter>(GetOwner());
	if (Character)
	{
		auto CharacterMovement = Character->GetCharacterMovement();
		CharacterMovement->SetMovementMode(EMovementMode::MOVE_Walking);

		auto Controller = Character->GetController();
		
		auto PC = Cast<APlayerController>(Controller);
		PC->bShowMouseCursor = false;
		
		//Character->EnableInput(PC);
	}
}

TArray<UTexture2D*> UMeshCustomizationComponent::GetAvailableTexturesForObject()
{
	auto PictureSceneActor = Cast<APicture_VoyagerARSceneActor>(BufferedActor);

	if (PictureSceneActor)
	{
		return PictureSceneActor->GetAvailableTexturesForObject();
	}
	TArray<UTexture2D*> BadArray;
	return BadArray;
}

void UMeshCustomizationComponent::SetTextureForObject(UTexture2D* Texture)
{
	auto CustomizableMaterial = BufferedActor->Mesh->CreateDynamicMaterialInstance(0);
	CustomizableMaterial->SetTextureParameterValue("CustomTexture", Texture);
}

void UMeshCustomizationComponent::GetAvailableCustomizationParams(FAvailableCustomizationParams& Params)
{
	if (BufferedActor)
	{
		Params.bCanChangeLocation = BufferedActor->bCanChangeLocation();
		Params.bCanChangeRotation = BufferedActor->bCanChangeRotation();
		Params.bCanChangeScale = BufferedActor->bCanChangeScale();
		Params.bCanChangeColor = BufferedActor->bCanChangeColor();
	}
}

void UMeshCustomizationComponent::ProcessPreviewActorRotation(float Value)
{
	if (PreviewActor)
		PreviewActor->SetPreviewActorRotation(Value);
}

void UMeshCustomizationComponent::ProcessPreviewActorScale(float Value)
{
	if (PreviewActor)
		PreviewActor->SetPreviewActorScale(Value);
}

// Called when the game starts
void UMeshCustomizationComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


void UMeshCustomizationComponent::ProcessLocationChange()
{
	auto OwnerChar = Cast<ACharacter>(GetOwner());
	auto Controller = OwnerChar->GetController();

	if (Controller)
	{
		auto PC = Cast<APlayerController>(Controller);
		FVector OutCamLoc;
		FRotator OutCamRot;
		PC->PlayerCameraManager->GetCameraViewPoint(OutCamLoc, OutCamRot);

		FHitResult HitResult;
		FCollisionQueryParams CollisionParams = FCollisionQueryParams::DefaultQueryParam;
		CollisionParams.bTraceComplex = true;
		
		GetWorld()->LineTraceSingleByChannel(HitResult, OutCamLoc, OutCamLoc + (250 * OutCamRot.Vector()), ECollisionChannel::ECC_Visibility, CollisionParams);

		PreviewActor->SetPreviewActorLocation(HitResult);
	}
}

void UMeshCustomizationComponent::ShowInteractionWidget(AVoyagerARSceneActor* NewFocusActor)
{
	FocusActor = NewFocusActor;
	FocusActor->ShowInteractionWidget();
}

void UMeshCustomizationComponent::HideInteractionWidget()
{
	if (!FocusActor) return;
	
	FocusActor->HideInteractionWidget();
	FocusActor = nullptr;
}
// Called every frame
void UMeshCustomizationComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (bCustomizationProcessStarted)
	{
		ProcessLocationChange();
	}
	// ...
}

