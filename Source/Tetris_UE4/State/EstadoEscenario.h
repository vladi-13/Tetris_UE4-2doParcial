// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EstadoEscenario.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UEstadoEscenario : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class TETRIS_UE4_API IEstadoEscenario
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public: 
	virtual void EstablecerEscenario(class AEscenarioState* _Escenario) = 0;
	virtual void SetEscenario(class AEscenarioState* Escenario) = 0;
};
