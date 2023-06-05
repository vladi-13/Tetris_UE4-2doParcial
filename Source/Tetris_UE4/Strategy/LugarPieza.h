// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PiezaStrategy.h"
#include "LugarPieza.generated.h"

UCLASS()
class TETRIS_UE4_API ALugarPieza : public AActor
{
	GENERATED_BODY()
	
private:
	IPiezaStrategy* PiezaStrategy;

public:
	void lugarPieza(AActor* piezaStrategy);
};
