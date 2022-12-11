// Fill out your copyright notice in the Description page of Project Settings.


#include "Picture_PreviewActor.h"

#include "DrawDebugHelpers.h"
#include "Components/StaticMeshComponent.h"

void APicture_PreviewActor::BeginPlay()
{
	AActor::BeginPlay();

	Mesh->SetMaterial(1, BlackoutMaterial);
	DynamicMaterial = Mesh->CreateDynamicMaterialInstance(1);
}

APicture_PreviewActor::APicture_PreviewActor()
{
	CheckPlaneTag = "wall";
}

void APicture_PreviewActor::ShowInteractionAction_Implementation()
{
	Super::ShowInteractionAction_Implementation();
}

void APicture_PreviewActor::SetPreviewActorLocation(const FHitResult& HitResult)
{
	FHitResult TargetHitResult;
	FVector EndPoint;
	FVector StartPoint;
	
	if (HitResult.Actor.IsValid())
	{
		//DrawDebugLine(GetWorld(), HitResult.Location, HitResult.Location + (HitResult.Normal * 200), FColor::Blue, false, 0.1, 0, 2);
		//DrawDebugLine(GetWorld(), HitResult.Location, HitResult.Location + (HitResult.ImpactNormal * 200), FColor::Yellow, false, 0.1, 0, 2);

		if (FMath::Abs(HitResult.ImpactNormal.Z) > 0.75)
		{
			//auto TraceDirection = HitResult.Location - HitResult.TraceStart;
			EndPoint = HitResult.Location + FVector(0.0f, 0.0f, 150);
		}
		else
		{
			EndPoint = HitResult.Location;
		}
		StartPoint = HitResult.TraceStart;
	}else
	{
		EndPoint = HitResult.TraceEnd + (HitResult.TraceEnd - HitResult.TraceStart) * 50;
		StartPoint = HitResult.TraceEnd;
	}
	

	FCollisionQueryParams Params;
	Params.bTraceComplex = true;
	Params.AddIgnoredActor(this);
	
	GetWorld()->LineTraceSingleByChannel(TargetHitResult, StartPoint, EndPoint, ECollisionChannel::ECC_Visibility, Params);

	DrawDebugLine(GetWorld(), StartPoint, TargetHitResult.Location, FColor::Emerald, false, 0.1, 0, 2);
	if (TargetHitResult.Actor.IsValid())
	{
		SetActorRotation(TargetHitResult.ImpactNormal.Rotation());
		SetActorLocation(TargetHitResult.Location + (TargetHitResult.ImpactNormal * 2));
	}else
	{
		SetActorLocation(TargetHitResult.TraceEnd);
	}

}
