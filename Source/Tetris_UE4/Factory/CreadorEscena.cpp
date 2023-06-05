// Fill out your copyright notice in the Description page of Project Settings.


#include "Factory/CreadorEscena.h"

// Sets default values
ACreadorEscena::ACreadorEscena()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACreadorEscena::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACreadorEscena::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

AEscena* ACreadorEscena::OrdenEscena(FString Category)
{
	AEscena* Escena = CreateEscena(Category);
	return Escena;
}