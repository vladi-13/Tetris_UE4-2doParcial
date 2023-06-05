// Fill out your copyright notice in the Description page of Project Settings.


#include "Decorator/RotacionDecorador.h"
#include "Block.h"

ARotacionDecorador::ARotacionDecorador()
{
	tiempoAcumulado = 0.0f;
}

void ARotacionDecorador::Rotar()
{
	UE_LOG(LogTemp, Warning, TEXT("Ahora puede rotar"));
	FRotator NewRotation = this->GetActorRotation() + FRotator(-1.0, 0.0, 0.0);
	this->SetActorRelativeRotation(NewRotation);
}

void ARotacionDecorador::SpawnBlocks()
{
	Super::SpawnBlocks();
}

void ARotacionDecorador::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (tiempoAcumulado >= 0.5)
	{
		UE_LOG(LogTemp, Warning, TEXT("now can move Estructura concreta"));
		Rotar();
		tiempoAcumulado = 0.0;
	}
	else
	{
		tiempoAcumulado += DeltaTime;
	}
}
