// Fill out your copyright notice in the Description page of Project Settings.


#include "Facade/PiezaFacade.h"

// Sets default values
APiezaFacade::APiezaFacade()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RaraDer = CreateDefaultSubobject<APiezaRaraDer>(TEXT("PiezaRaraDer"));
	RaraIzq = CreateDefaultSubobject<APiezaRaraIzq>(TEXT("PiezaRaraIzq"));
}

void APiezaFacade::SpawnRaraDerBlocks()
{
	RaraDer->SpawnBlocksDer();
}

void APiezaFacade::SpawnRaraIzqBlocks()
{
	RaraIzq->SpawnBlocksIzq();
}