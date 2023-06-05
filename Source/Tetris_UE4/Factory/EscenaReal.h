// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factory/CreadorEscena.h"
#include "EscenaReal.generated.h"

/**
 * 
 */
UCLASS()
class TETRIS_UE4_API AEscenaReal : public ACreadorEscena
{
	GENERATED_BODY()
	
public:

	virtual AEscena* CreateEscena(FString NameEscena) override; //Funcion para la creacion de escenas
};
