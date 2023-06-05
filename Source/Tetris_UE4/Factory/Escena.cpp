// Fill out your copyright notice in the Description page of Project Settings.


#include "Factory/Escena.h"

// Sets default values
AEscena::AEscena()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> EscenaMesh(TEXT("StaticMesh'/Game/Mesh/block.block'"));
	M_Escena = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Escena"));
	M_Escena->SetStaticMesh(EscenaMesh.Object);
	SetRootComponent(M_Escena);
}

// Called when the game starts or when spawned
void AEscena::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEscena::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

