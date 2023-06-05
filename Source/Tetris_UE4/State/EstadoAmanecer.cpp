// Fill out your copyright notice in the Description page of Project Settings.


#include "State/EstadoAmanecer.h"
#include "State/EscenarioState.h"

// Sets default values
AEstadoAmanecer::AEstadoAmanecer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	materialEscenarioManana = LoadObject<UMaterialInterface>(nullptr, TEXT("Material'/Game/Blueprints/paisaje_de_dia_Mat.paisaje_de_dia_Mat'"));
}

// Called when the game starts or when spawned
void AEstadoAmanecer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEstadoAmanecer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEstadoAmanecer::EstablecerEscenario(AEscenarioState* _Escenario)
{
    _Escenario->MeshEscenario->SetMaterial(0, materialEscenarioManana);
    EscenarioState->cambiarEstado(EscenarioState->getEstadoTarde());
}

void AEstadoAmanecer::SetEscenario(AEscenarioState* _Escenario)
{
	EscenarioState = _Escenario;
}

