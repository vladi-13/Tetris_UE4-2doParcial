// Fill out your copyright notice in the Description page of Project Settings.


#include "Builder/PiezaConstruida.h"
#include "Pieces.h"
#include "Builder/BloqueExplosivo.h"
#include "Builder/BloqueHielo.h"
#include "Builder/BloqueMadera.h"
#include "Builder/BloqueMetal.h"
#include "Builder/BloquePiedra.h"

// Sets default values
APiezaConstruida::APiezaConstruida()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called every frame
void APiezaConstruida::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APiezaConstruida::buildBloqueMadera()
{
	if (!Pieza) {
		UE_LOG(LogTemp, Error, TEXT("buildBloqueMadera(): Pieza es NULL, asegúrese de que esté inicializado."));
		return;
	}
	// Construir bloque de madera
	Pieza->setBloqueMadera();
}

void APiezaConstruida::buildBloqueMetal()
{
	if (!Pieza) {
		UE_LOG(LogTemp, Error, TEXT("buildBloqueMetal(): Pieza es NULL, asegúrese de que esté inicializado."));
		return;
	}
	// Construir bloque de metal
	Pieza->setBloqueMetal();
}

void APiezaConstruida::buildBloqueHielo()
{
	if (!Pieza) {
		UE_LOG(LogTemp, Error, TEXT("buildBloqueHielo(): Pieza es NULL, asegúrese de que esté inicializado."));
		return;
	}
	// Construir bloque de hielo
	Pieza->setBloqueHielo();
}

void APiezaConstruida::buildBloqueExplosivo()
{
	if (!Pieza) {
		UE_LOG(LogTemp, Error, TEXT("buildBloqueExplosivo(): Pieza es NULL, asegúrese de que esté inicializado."));
		return;
	}
	// Construir bloque explosivo
	Pieza->setBloqueExplosivo();
}

void APiezaConstruida::buildBloquePiedra()
{
	if (!Pieza) {
		UE_LOG(LogTemp, Error, TEXT("buildBloquePiedra(): Pieza es NULL, asegúrese de que esté inicializado."));
		return;
	}
	// Construir bloque de piedra
	Pieza->setBloquePiedra();
}