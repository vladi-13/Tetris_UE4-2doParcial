// Fill out your copyright notice in the Description page of Project Settings.


#include "Adapter/AdapterMovimientoPieza_Ca.h"

UAdapterMovimientoPieza_Ca::UAdapterMovimientoPieza_Ca() 
{
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	SetLimitesMovimiento(0.0f, 5.0f, 5.0f);
}

void UAdapterMovimientoPieza_Ca::SetLimitesMovimiento(float _XMovimiento, float _YMovimiento, float _ZMovimiento)
{
	AnchoMovimiento = _XMovimiento;
	AltoMovimiento = _YMovimiento;
	ProfundidadMovimiento = _ZMovimiento;
}
