// Fill out your copyright notice in the Description page of Project Settings.


#include "Factory/EscenaMario.h"

AEscenaMario::AEscenaMario() 
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> PowerMeshAsset(TEXT("StaticMesh'/Game/Mesh/Power.Power'"));
	if (PowerMeshAsset.Succeeded())
	{
		M_Escena->SetStaticMesh(PowerMeshAsset.Object);
		M_Escena->SetWorldScale3D(FVector(10.0f, 50.0f, 30.0f));
	}
}

void AEscenaMario::BeginPlay()
{
	Super::BeginPlay();
	EscenaName = "Super";
}