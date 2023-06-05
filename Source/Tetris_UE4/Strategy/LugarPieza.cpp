// Fill out your copyright notice in the Description page of Project Settings.


#include "Strategy/LugarPieza.h"

void ALugarPieza::lugarPieza(AActor* piezaStrategy)
{
	PiezaStrategy = Cast<IPiezaStrategy>(piezaStrategy);
	PiezaStrategy->SpawnBlocks();
}