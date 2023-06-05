// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Estructura.h"
#include "EstructuraConcreta.generated.h"

UCLASS()
class TETRIS_UE4_API AEstructuraConcreta : public AActor , public IEstructura
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEstructuraConcreta();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Rotar() override;
	virtual void SpawnBlocks() override;

	UPROPERTY()
		TArray<class UMaterial*> Colors;

private:
	float tiempoAcumulado;
};
