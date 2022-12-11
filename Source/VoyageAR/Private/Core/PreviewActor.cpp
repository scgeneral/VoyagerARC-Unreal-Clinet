// Fill out your copyright notice in the Description page of Project Settings.


#include "PreviewActor.h"

#include "DrawDebugHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"

// Sets default values
APreviewActor::APreviewActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	WidgetComponent = CreateDefaultSubobject<UWidgetComponent>("InteractWidget");
	Mesh->OnComponentBeginOverlap.AddDynamic(this, &APreviewActor::HandlePreviewActorOverlap);
}

void APreviewActor::InitPreviewMeshMetaData(FMeshInfo MeshMetaData)
{
	CurrentMeshMetaData = MeshMetaData;
}

// Called when the game starts or when spawned
void APreviewActor::BeginPlay()
{
	Super::BeginPlay();
	Mesh->SetMaterial(0, BlackoutMaterial);
	DynamicMaterial = Mesh->CreateDynamicMaterialInstance(0);
}

void APreviewActor::CheckPreviewActorOverlapCorrectPlane(const FString& CorrectActorTag)
{
	bNowOverlapWrongCollision = false;

	TArray<AActor*> OutOverlappingActors;
	GetOverlappingActors(OutOverlappingActors);
	
	for (const auto Actor : OutOverlappingActors)
	{
		if (!Actor->Tags.Contains(*CorrectActorTag))
		{
			DynamicMaterial->SetVectorParameterValue("Color", FColor::Red);
			bNowOverlapWrongCollision = true;
		}	
	}

	if (OutOverlappingActors.Num() == 0)
	{
		DynamicMaterial->SetVectorParameterValue("Color", FColor::Red);
		bNowOverlapWrongCollision = true;
	}
	
	if (!bNowOverlapWrongCollision)
		DynamicMaterial->SetVectorParameterValue("Color", FColor::White);
}

// Called every frame
void APreviewActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CheckPreviewActorOverlapCorrectPlane(CheckPlaneTag);
}

void APreviewActor::ShowInteractionAction_Implementation()
{
}

void APreviewActor::SetPreviewActorLocation(const FHitResult& HitResult)
{
	FHitResult TargetHitResult;
	FVector EndPoint;
	FVector StartPoint;
	
	if (HitResult.Actor.IsValid())
	{
		EndPoint = HitResult.Location - FVector(0.0f, 0.0f, 400);
		StartPoint = HitResult.Location;
	}else
	{
		EndPoint = HitResult.TraceEnd - FVector(0.0f, 0.0f, 400);
		StartPoint = HitResult.TraceEnd;
	}
	

	FCollisionQueryParams Params;
	Params.bTraceComplex = true;
	Params.AddIgnoredActor(this);
	
	GetWorld()->LineTraceSingleByChannel(TargetHitResult, StartPoint, EndPoint, ECollisionChannel::ECC_Visibility, Params);

	DrawDebugLine(GetWorld(), StartPoint, TargetHitResult.Location, FColor::Emerald, false, 0.1, 0, 2);
	if (TargetHitResult.Actor.IsValid())
	{
		SetActorLocation(TargetHitResult.Location);
	}else
	{
		SetActorLocation(TargetHitResult.TraceEnd);
	}
}

void APreviewActor::SetPreviewActorRotation(float DeltaRotation)
{
	auto NewRotation = GetActorRotation();
	NewRotation.Yaw += DeltaRotation;
	SetActorRotation(NewRotation);
}

void APreviewActor::SetPreviewActorScale(float DeltaScale)
{
	auto Scale = GetActorScale3D();

	const auto NewScaleX = FMath::Clamp(Scale.X + DeltaScale / 20, 0.5f, 1.5f);
	const auto NewScaleY = FMath::Clamp(Scale.Y + DeltaScale / 20, 0.5f, 1.5f);
	const auto NewScaleZ = FMath::Clamp(Scale.Z + DeltaScale / 20, 0.5f, 1.5f);
	
	SetActorScale3D(FVector(NewScaleX, NewScaleY, NewScaleZ));
}

void APreviewActor::HandlePreviewActorOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                              UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//TArray<AActor*> OutOverlappingActors;
	//GetOverlappingActors(OutOverlappingActors);

	//bNowOverlapWrongCollision = false;
}


