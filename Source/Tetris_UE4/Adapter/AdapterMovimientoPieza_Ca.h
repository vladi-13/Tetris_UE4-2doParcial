// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Adapter/MovimientoBloque_CA.h"
#include "Adapter/MovimientoPieza.h"
#include "AdapterMovimientoPieza_Ca.generated.h"

/**
 * 
 */
UCLASS()
class TETRIS_UE4_API UAdapterMovimientoPieza_Ca : public UMovimientoBloque_CA , public IMovimientoPieza
{
	GENERATED_BODY()
	
public:
	UAdapterMovimientoPieza_Ca();
	void SetLimitesMovimiento(float _XMovimiento, float _YMovimiento, float _ZMovimiento);
};
