// Fill out your copyright notice in the Description page of Project Settings.


#include "State/EstadoAnochecer.h"
#include "State/EscenarioState.h"

// Sets default values
AEstadoAnochecer::AEstadoAnochecer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	materialEscenarioManana = LoadObject<UMaterialInterface>(nullptr, TEXT("Material'/Game/Blueprints/noche_paisaje_Mat.noche_paisaje_Mat'"));
}

// Called when the game starts or when spawned
void AEstadoAnochecer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEstadoAnochecer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEstadoAnochecer::EstablecerEscenario(AEscenarioState* _Escenario)
{
    _Escenario->MeshEscenario->SetMaterial(0, materialEscenarioManana);
    EscenarioState->cambiarEstado(EscenarioState->getEstadoManana());
}

void AEstadoAnochecer::SetEscenario(AEscenarioState* _Escenario)
{
	EscenarioState = _Escenario;
}

