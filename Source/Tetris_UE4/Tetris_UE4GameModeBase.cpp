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
#include "Camera/CameraActor.h"
#include "Kismet/GameplayStatics.h"
#include "EngineUtils.h"

ATetris_UE4GameModeBase::ATetris_UE4GameModeBase()
{
    DefaultPawnClass = ABoard::StaticClass();
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

    // Sistema para la creacion de piezas
    PiezaConstruida = GetWorld()->SpawnActor<APiezaConstruida>(APiezaConstruida::StaticClass());
    // Creamos a la pieza ing 
    PiezaIng = GetWorld()->SpawnActor<APiezaIng>(APiezaIng::StaticClass());
    PiezaIng->SetPiezaBuilder(PiezaConstruida);

    // Creamos los bloques
    //GetWorld()->SpawnActor<ABloqueMadera>(ABloqueMadera::StaticClass());
    //PiezaIng->ConstructorPieza("Madera");

    //GetWorld()->SpawnActor<ABloqueMetal>(ABloqueMetal::StaticClass());
    //PiezaIng->ConstructorPieza("Metal");

    //GetWorld()->SpawnActor<ABloqueHielo>(ABloqueHielo::StaticClass());
    //PiezaIng->ConstructorPieza("Hielo");

    //GetWorld()->SpawnActor<ABloqueExplosivo>(ABloqueExplosivo::StaticClass());
    //PiezaIng->ConstructorPieza("Explosivo");

    //GetWorld()->SpawnActor<ABloquePiedra>(ABloquePiedra::StaticClass());
    //PiezaIng->ConstructorPieza("Piedra");

}
