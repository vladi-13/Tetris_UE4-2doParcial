// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factory/Escena.h"
#include "EscenaMC.generated.h"

/**
 * 
 */
UCLASS()
class TETRIS_UE4_API AEscenaMC : public AEscena
{
	GENERATED_BODY()
		
public:
	// Sets default values for this actor's properties
	AEscenaMC();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
