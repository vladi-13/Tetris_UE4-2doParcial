// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Block.h"
#include "Builder/PiezaPlano.h"
#include "Observer/Observer.h"
#include <functional>
#include <vector>
#include "Pieces.generated.h"

UCLASS()
class TETRIS_UE4_API APieces : public AActor , public IPiezaPlano, public IObserver
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APieces();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
    
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

    UPROPERTY()
    class USceneComponent* SceneComponent;
    
    UPROPERTY()
    class USoundCue* RotateSoundCue;
    
    UPROPERTY()
    class USoundCue* MoveLeftRightSoundCue;
    
    UPROPERTY()
    TArray<class UMaterial*> Colors;
    
    void DrawDebugLines();
    
    void TestRotate();
    void MoveLeft();
    void MoveRight();
    bool MoveDown(bool PlaySound=true);
    void Dismiss();
    // 检查当前的形状在某个位置时是否会与其它方块碰撞。
    // 参数ChangeBeforeCheck是一个回调函数，输入要将当前的格子移动到哪里去，向下向左向右或是旋转，用不同的回调函数即可。
    bool CheckWillCollision(std::function<FVector(FVector OldLocation)> ChangeBeforeCheck);
private:
    TArray<ABlock*> Blocks;
    void SpawnBlocks();

public:
    // Metodos para construir los bloques
    void setBloqueMadera() override;
    void setBloquePiedra() override;
    void setBloqueExplosivo() override;
    void setBloqueMetal() override;
    void setBloqueHielo() override;

    // Metodos para los suscriptores
    virtual void Update() override;
    void Attach(IObserver* observer);
    void Detach(IObserver* observer);
    void Notify();

    int subscriberCount;

private:
    std::vector<IObserver*> observers;
};
