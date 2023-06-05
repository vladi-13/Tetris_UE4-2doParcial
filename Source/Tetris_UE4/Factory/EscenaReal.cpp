// Fill out your copyright notice in the Description page of Project Settings.


#include "Factory/EscenaReal.h"
#include "Factory/EscenaBase.h"
#include "Factory/EscenaMario.h"
#include "Factory/EscenaMC.h"
#include "Kismet/GameplayStatics.h"

AEscena* AEscenaReal::CreateEscena(FString NameEscena)
{
    FVector Spawn(100.0f, 0.0f, 60.0f);

    // Busca el actor existente en la misma ubicación
    TArray<AActor*> Actors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEscena::StaticClass(), Actors);

    for (AActor* Actor : Actors)
    {
        if (Actor->GetActorLocation() == Spawn)
        {
            // Destruye el actor existente en la misma ubicación
            Actor->Destroy();
            break;
        }
    }

    if (NameEscena.Equals("Tetris")) {
        return GetWorld()->SpawnActor<AEscenaBase>(Spawn, FRotator::ZeroRotator);
    }
    else if (NameEscena.Equals("Super")) {
        return GetWorld()->SpawnActor<AEscenaMario>(Spawn, FRotator::ZeroRotator);
    }
    else if (NameEscena.Equals("Mine")) {
        return GetWorld()->SpawnActor<AEscenaMC>(Spawn, FRotator::ZeroRotator);
    }
    else return nullptr;
}