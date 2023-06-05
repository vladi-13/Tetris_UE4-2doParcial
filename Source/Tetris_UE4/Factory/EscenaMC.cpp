// Fill out your copyright notice in the Description page of Project Settings.


#include "Factory/EscenaMC.h"
#include "UObject/ConstructorHelpers.h"

AEscenaMC::AEscenaMC()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SkyMeshAsset(TEXT("StaticMesh'/Game/Mesh/Sky.Sky'"));
	if (SkyMeshAsset.Succeeded())
	{
		M_Escena->SetStaticMesh(SkyMeshAsset.Object);
		M_Escena->SetWorldScale3D(FVector(10.0f, 50.0f, 30.0f));
	}
}

void AEscenaMC::BeginPlay()
{
	Super::BeginPlay();
	EscenaName = "Mine";
}