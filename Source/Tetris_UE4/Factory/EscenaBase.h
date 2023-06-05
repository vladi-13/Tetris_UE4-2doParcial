// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factory/Escena.h"
#include "EscenaBase.generated.h"

/**
 * 
 */
UCLASS()
class TETRIS_UE4_API AEscenaBase : public AEscena
{
	GENERATED_BODY()
	
public:
	AEscenaBase(); //Constructor

protected:

	virtual void BeginPlay() override;
};
