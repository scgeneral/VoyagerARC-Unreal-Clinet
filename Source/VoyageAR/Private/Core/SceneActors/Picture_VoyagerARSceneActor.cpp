// Fill out your copyright notice in the Description page of Project Settings.


#include "Picture_VoyagerARSceneActor.h"

APicture_VoyagerARSceneActor::APicture_VoyagerARSceneActor()
{
	ActorType = MeshType::EFurniture;
}

TArray<UTexture2D*> APicture_VoyagerARSceneActor::	GetAvailableTexturesForObject()
{
	return AvailableTextures;
}
