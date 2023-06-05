// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Block.h"
#include "PiezaRaraDer.generated.h"

UCLASS()
class TETRIS_UE4_API APiezaRaraDer : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APiezaRaraDer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	virtual void SpawnBlocksDer();

	UPROPERTY()
		TArray<class UMaterial*> Colors;

private:
	TArray<ABlock*> Blocks;
};
