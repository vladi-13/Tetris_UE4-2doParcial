// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Escena.h"
#include "CreadorEscena.generated.h"

UCLASS(Abstract)
class TETRIS_UE4_API ACreadorEscena : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACreadorEscena();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual AEscena* CreateEscena(FString NameEscena) PURE_VIRTUAL(ACreadorEscena::CreateEscena, return nullptr;); //Funcion virtual pura a escena

	AEscena* OrdenEscena(FString Category); //Funcion para la creacion de escenas
};
