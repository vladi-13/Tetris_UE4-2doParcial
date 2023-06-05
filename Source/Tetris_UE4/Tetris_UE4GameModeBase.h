// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Block.h"
#include "Pieces.h"
#include "Adapter/AdapterMovimientoPieza_Ca.h"
#include "Decorator/EstructuraConcreta.h"
#include "Decorator/RotacionDecorador.h"
#include "GameFramework/GameModeBase.h"
#include "Tetris_UE4GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class TETRIS_UE4_API ATetris_UE4GameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
    ATetris_UE4GameModeBase();
    
    virtual void BeginPlay() override;

    virtual void Tick(float DeltaSeconds) override;

    UPROPERTY()
        APieces* SpawnedPiece;
        APieces* SpawnedPiece2;

    //Patron singleton para que no se creen mas de dos "boards"
    class ABoard* Board;

    //Movimientos de las piezas adapter
    UPROPERTY()
        UAdapterMovimientoPieza_Ca* MovimientoPieza;
        UAdapterMovimientoPieza_Ca* MovimientoPieza2;

    //Estructura concreta para el uso de decorador
    UPROPERTY()
		AEstructuraConcreta* EstructuraConcreta;
        AEstructuraConcreta* EstructuraConcreta2;

        ARotacionDecorador* RotacionDecorador;  
        ARotacionDecorador* RotacionDecorador2;

private:
    //Declarando propiedades para el uso de la creacion de piezas
    class APiezaIng* PiezaIng;
    class APiezaConstruida* PiezaConstruida;

    //Tiempo de la escena
    float tiempoEscena;
};
