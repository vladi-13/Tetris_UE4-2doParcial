// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PiezaBuilder.h"
#include "PiezaIng.generated.h"

UCLASS()
class TETRIS_UE4_API APiezaIng : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APiezaIng();

private:
	IPiezaBuilder* PiezaBuilder;

public:
	//Crea las piezas
	void ConstructorPieza(FString _tipoBloque);

	//Establecer el actor constructor
	void SetPiezaBuilder(AActor* Builder);
};
