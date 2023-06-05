// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Escena.generated.h"

UCLASS()
class TETRIS_UE4_API AEscena : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEscena();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* M_Escena; //Malla de la escena

	UPROPERTY()
		class UMaterialInterface* C_Escena; //Material de la escena

	FString EscenaName; //Nombre de las escenas

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FString GetEscenaName() const { return EscenaName; } //Obtenemos el nombre de las escenas
};
