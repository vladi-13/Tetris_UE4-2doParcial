// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PiezaBuilder.h"
#include "PiezaConstruida.generated.h"

UCLASS()
class TETRIS_UE4_API APiezaConstruida : public AActor, public IPiezaBuilder
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APiezaConstruida();

private:
	class APieces* Pieza;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void buildBloqueMadera() override;
	virtual void buildBloquePiedra() override;
	virtual void buildBloqueExplosivo() override;
	virtual void buildBloqueMetal() override;
	virtual void buildBloqueHielo() override;
};
