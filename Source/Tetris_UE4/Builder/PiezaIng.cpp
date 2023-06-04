// Fill out your copyright notice in the Description page of Project Settings.


#include "Builder/PiezaIng.h"
#include "Pieces.h"

// Sets default values
APiezaIng::APiezaIng()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void APiezaIng::ConstructorPieza(FString _tipoBloque)
{
	//Registrar si el constructor es NULL
	if (!PiezaBuilder) {
		UE_LOG(LogTemp, Error, TEXT("ConstructorPieza(): PiezaBuilder es NULL, asegúrese de que esté inicializado."));
		return;
	}

	//Construir la pieza
	if (_tipoBloque == "Madera") {
		PiezaBuilder->buildBloqueMadera();
	}
	else if (_tipoBloque == "Piedra") {
		PiezaBuilder->buildBloquePiedra();
	}
	else if (_tipoBloque == "Explosivo") {
		PiezaBuilder->buildBloqueExplosivo();
	}
	else if (_tipoBloque == "Metal") {
		PiezaBuilder->buildBloqueMetal();
	}
	else if (_tipoBloque == "Hielo") {
		PiezaBuilder->buildBloqueHielo();
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("ConstructorPieza(): Tipo de bloque no reconocido."));
	}
}

void APiezaIng::SetPiezaBuilder(AActor* Builder)
{
	//Establecer el constructor
	PiezaBuilder = Cast<IPiezaBuilder>(Builder);

	//Registrar si el constructor es NULL
	if (!PiezaBuilder) {
		UE_LOG(LogTemp, Error, TEXT("SetPiezaBuilder(): PiezaBuilder es NULL, asegúrese de que esté inicializado."));
		return;
	}
}