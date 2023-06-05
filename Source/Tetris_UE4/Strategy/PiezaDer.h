// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PiezaStrategy.h"
#include "Block.h"
#include "PiezaDer.generated.h"

UCLASS()
class TETRIS_UE4_API APiezaDer : public AActor, public IPiezaStrategy
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APiezaDer();
public:	
	// Called every frame
	virtual void Tick(float DeltaSeconds) override;
	virtual void SpawnBlocks() override;

	float tiempoAparecido;
	float tiempoVisible;

	UPROPERTY()
		TArray<class UMaterial*> Colors;

private:
	TArray<ABlock*> Blocks;
};
