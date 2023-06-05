// Fill out your copyright notice in the Description page of Project Settings.


#include "Factory/EscenaBase.h"

AEscenaBase::AEscenaBase()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> HealthMeshAsset(TEXT("StaticMesh'/Game/Mesh/Health.Health'"));
	if (HealthMeshAsset.Succeeded())
	{
		M_Escena->SetStaticMesh(HealthMeshAsset.Object);
		M_Escena->SetWorldScale3D(FVector(10.0f, 50.0f, 30.0f));
	}
}

void AEscenaBase::BeginPlay()
{
	Super::BeginPlay();
	EscenaName = "Tetris";
}