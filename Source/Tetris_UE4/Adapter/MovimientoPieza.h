// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MovimientoPieza.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UMovimientoPieza : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class TETRIS_UE4_API IMovimientoPieza
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	float DistanciaX;
	float DistanciaY;
	float DistanciaZ;
	float TiempoTranscurrido;
	float TiempoLimite;
};
