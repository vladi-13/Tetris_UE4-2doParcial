// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "State/EstadoEscenario.h"
#include "EstadoAnochecer.generated.h"

UCLASS()
class TETRIS_UE4_API AEstadoAnochecer : public AActor, public IEstadoEscenario
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEstadoAnochecer();

private:

	UPROPERTY()
		class AEscenarioState* EscenarioState;

	UMaterialInterface* materialEscenarioManana;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void EstablecerEscenario(class AEscenarioState* _Escenario) override;
	virtual void SetEscenario(class AEscenarioState* _Escenario) override;
};
