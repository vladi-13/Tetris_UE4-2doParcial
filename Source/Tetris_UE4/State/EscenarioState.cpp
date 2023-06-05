// Fill out your copyright notice in the Description page of Project Settings.


#include "State/EscenarioState.h"
#include "State/EstadoEscenario.h"
#include "State/EstadoAmanecer.h"
#include "State/EstadoAterdecer.h"
#include "State/EstadoAnochecer.h"

// Sets default values
AEscenarioState::AEscenarioState()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    MeshEscenario = CreateDefaultSubobject<UStaticMeshComponent>("Escenario Mesh");
    RootComponent = MeshEscenario;

    static ConstructorHelpers::FObjectFinder<UStaticMesh> Escenarios(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Plane.Shape_Plane'"));
    if (Escenarios.Succeeded())
    {
        MeshEscenario->SetStaticMesh(Escenarios.Object);
        MeshEscenario->SetRelativeLocation(FVector(1000.0f, 1000.0f, 1000.0f));
        MeshEscenario->SetWorldScale3D(FVector(5.0f, 3.0f, 2.5f));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("mesh not found"));
    }

    materialEscenarioManana = LoadObject<UMaterialInterface>(nullptr, TEXT("Material'/Game/Blueprints/tetris_Mat.tetris_Mat'"));
}

// Called when the game starts or when spawned
void AEscenarioState::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEscenarioState::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

AEscenarioState* AEscenarioState::iniciar()
{
    EstadoAmanecer = GetWorld()->SpawnActor<AEstadoAmanecer>(AEstadoAmanecer::StaticClass());
    EstadoAmanecer->SetEscenario(this);

    EstadoAterdecer = GetWorld()->SpawnActor<AEstadoAterdecer>(AEstadoAterdecer::StaticClass());
    EstadoAterdecer->SetEscenario(this);

    EstadoAnochecer = GetWorld()->SpawnActor<AEstadoAnochecer>(AEstadoAnochecer::StaticClass());
    EstadoAnochecer->SetEscenario(this);

    FTransform SpawnLocation;
    AEscenarioState* EscenarioState = GetWorld()->SpawnActor<AEscenarioState>(AEscenarioState::StaticClass(), SpawnLocation);
    EscenarioState->MeshEscenario->SetMaterial(0, materialEscenarioManana);
    EscenarioState->SetActorRelativeLocation(FVector(260.0, -25.0, 100.0));
    EscenarioState->SetActorRelativeRotation(FRotator(0.0, 90.0, 90.0));

    Estado = EstadoAmanecer;
    return EscenarioState;
}

void AEscenarioState::cambiarEscenario(AEscenarioState* _Escenario)
{
    Estado->EstablecerEscenario(_Escenario);
}

void AEscenarioState::cambiarEstado(IEstadoEscenario* _Estado)
{
    Estado = _Estado;
}

IEstadoEscenario* AEscenarioState::getEstadoManana()
{
	return EstadoAmanecer;
}

IEstadoEscenario* AEscenarioState::getEstadoTarde()
{
    return EstadoAterdecer;
}

IEstadoEscenario* AEscenarioState::getEstadoNoche()
{
	return EstadoAnochecer;
}

IEstadoEscenario* AEscenarioState::getEstado()
{
	return Estado;
}

