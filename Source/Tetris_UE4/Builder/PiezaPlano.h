// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PiezaPlano.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UPiezaPlano : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class TETRIS_UE4_API IPiezaPlano
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	// Las funciones virtuales puras de Pieza Plano
	virtual void setBloqueMadera() = 0;
	virtual void setBloquePiedra() = 0;
	virtual void setBloqueExplosivo() = 0;
	virtual void setBloqueMetal() = 0;
	virtual void setBloqueHielo() = 0;
};
