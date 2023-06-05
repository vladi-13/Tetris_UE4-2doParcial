// Fill out your copyright notice in the Description page of Project Settings.


#include "Tetris_UE4GameModeBase.h"
#include "Board.h"
#include "Builder/BloqueMadera.h"
#include "Builder/BloqueMetal.h"
#include "Builder/BloqueHielo.h"
#include "Builder/BloqueExplosivo.h"
#include "Builder/BloquePiedra.h"
#include "Builder/PiezaIng.h"
#include "Builder/PiezaConstruida.h"
#include "Factory/CreadorEscena.h"
#include "Factory/EscenaReal.h"
#include "Factory/Escena.h"
#include "Camera/CameraActor.h"
#include "Kismet/GameplayStatics.h"
#include "EngineUtils.h"


ATetris_UE4GameModeBase::ATetris_UE4GameModeBase()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    DefaultPawnClass = ABoard::StaticClass();

    tiempoEscena = 0.0f;
}

void ATetris_UE4GameModeBase::BeginPlay()
{
    Super::BeginPlay();
    
    for(TActorIterator<ACameraActor> it(GetWorld()); it; ++it)
    {
        //UE_LOG(LogTemp, Warning, TEXT("Find camera: %s"), *(it->GetFName().ToString()));
        if(it->GetFName() == TEXT("BoardCamera"))
        {
            APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
            PC->SetViewTargetWithBlend(*it, 0.5);
            break;
        }
    }

    //SINGLETON
    //Ciclo para que aparezca el board con el patron singleton
    for (int i = 0; i < 1; i++)
    {
   	ABoard* Aparecio = GetWorld() -> SpawnActor<ABoard>(ABoard::StaticClass());
   	if (Aparecio)
   	{
   		Board = Aparecio;
   		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,FString::Printf(TEXT("%s El board está apareciendo"),*Board->GetName()));
   	}
    }

    //BUILDER
    // Sistema para la creacion de piezas
    PiezaConstruida = GetWorld()->SpawnActor<APiezaConstruida>(APiezaConstruida::StaticClass());
    // Creamos a la pieza ing 
    PiezaIng = GetWorld()->SpawnActor<APiezaIng>(APiezaIng::StaticClass());
    PiezaIng->SetPiezaBuilder(PiezaConstruida);

    //ADAPTER
    FVector UbicacionBloque(0.0, 120.0, 140.0);
    SpawnedPiece = GetWorld()->SpawnActor<APieces>(UbicacionBloque, FRotator::ZeroRotator);
    MovimientoPieza = NewObject<UAdapterMovimientoPieza_Ca>(SpawnedPiece);
    MovimientoPieza->RegisterComponent();

    FVector UbicacionPieza(0.0, 120.0, 70.0);
    SpawnedPiece2 = GetWorld()->SpawnActor<APieces>(UbicacionPieza, FRotator::ZeroRotator);
    MovimientoPieza2 = NewObject<UAdapterMovimientoPieza_Ca>(SpawnedPiece2);
    MovimientoPieza2->RegisterComponent();

    //DECORATOR
    FVector UbicacionDecorador(0.0, -120.0, 140.0);
    EstructuraConcreta = GetWorld()->SpawnActor<AEstructuraConcreta>(UbicacionDecorador, FRotator::ZeroRotator);
    RotacionDecorador = GetWorld()->SpawnActor<ARotacionDecorador>(ARotacionDecorador::StaticClass());
    RotacionDecorador->SetEstructura(EstructuraConcreta);

    FVector UbicacionDecorador2(0.0, -120.0, 70.0);
    EstructuraConcreta2 = GetWorld()->SpawnActor<AEstructuraConcreta>(UbicacionDecorador2, FRotator::ZeroRotator);
    RotacionDecorador2 = GetWorld()->SpawnActor<ARotacionDecorador>(ARotacionDecorador::StaticClass());
    RotacionDecorador2->SetEstructura(EstructuraConcreta2);
}

void ATetris_UE4GameModeBase::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

    //FACTORY
    tiempoEscena += DeltaSeconds;
    if (tiempoEscena > 10) {
        AEscena* Escena;
        ACreadorEscena* EscenaCreator = GetWorld()->SpawnActor<AEscenaReal>(AEscenaReal::StaticClass());
        const int random = FMath::RandRange(1, 3);
        switch (random) {
        case 1:
            Escena = EscenaCreator->OrdenEscena("Tetris");
            break;
        case 2:
            Escena = EscenaCreator->OrdenEscena("Super");
            break;
        case 3:
            Escena = EscenaCreator->OrdenEscena("Mine");
            break;
        default:
            break;
        }
        tiempoEscena = 0.0f;
    }

    //DECORATOR
    EstructuraConcreta->Rotar();
    RotacionDecorador->Rotar();
}
