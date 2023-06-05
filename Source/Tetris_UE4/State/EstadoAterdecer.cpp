// Fill out your copyright notice in the Description page of Project Settings.


#include "State/EstadoAterdecer.h"
#include "State/EscenarioState.h"

// Sets default values
AEstadoAterdecer::AEstadoAterdecer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	materialEscenarioManana = LoadObject<UMaterialInterface>(nullptr, TEXT("Material'/Game/Blueprints/atardecer_paisaje_Mat.atardecer_paisaje_Mat'"));
}

// Called when the game starts or when spawned
void AEstadoAterdecer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEstadoAterdecer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEstadoAterdecer::EstablecerEscenario(AEscenarioState* _Escenario)
{
	_Escenario->MeshEscenario->SetMaterial(0, materialEscenarioManana);
	EscenarioState->cambiarEstado(EscenarioState->getEstadoNoche());
}

void AEstadoAterdecer::SetEscenario(AEscenarioState* _Escenario)
{
	EscenarioState = _Escenario;
}

