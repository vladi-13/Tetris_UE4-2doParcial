// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Decorator/Decorador.h"
#include "RotacionDecorador.generated.h"

/**
 * 
 */
UCLASS()
class TETRIS_UE4_API ARotacionDecorador : public ADecorador
{
	GENERATED_BODY()
	
public:
	ARotacionDecorador();
	void Rotar() override;
	void SpawnBlocks() override;

	virtual void Tick(float DeltaTime) override;

private:
	float tiempoAcumulado;
};
