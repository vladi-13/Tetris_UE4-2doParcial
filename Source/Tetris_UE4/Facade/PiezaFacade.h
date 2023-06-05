// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PiezaRaraDer.h"
#include "PiezaRaraIzq.h"
#include "PiezaFacade.generated.h"

UCLASS()
class TETRIS_UE4_API APiezaFacade : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APiezaFacade();

	void SpawnRaraDerBlocks();
	void SpawnRaraIzqBlocks();

private:
	UPROPERTY()
		APiezaRaraDer* RaraDer;

	UPROPERTY()
		APiezaRaraIzq* RaraIzq;

};
