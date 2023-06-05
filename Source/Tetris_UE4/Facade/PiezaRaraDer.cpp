// Fill out your copyright notice in the Description page of Project Settings.



#include "Facade/PiezaRaraDer.h"
#include "Builder/BloqueMadera.h"
#include "Builder/BloqueMetal.h"
#include "Builder/BloqueHielo.h"
#include "Builder/BloqueExplosivo.h"
#include "Builder/BloquePiedra.h"
#include "Components/SceneComponent.h"
#include "Kismet/GameplayStatics.h"
#include <vector>

// Sets default values
APiezaRaraDer::APiezaRaraDer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    struct FConstructorStatics
    {
        ConstructorHelpers::FObjectFinderOptional<UMaterial> Color_0;
        ConstructorHelpers::FObjectFinderOptional<UMaterial> Color_1;
        ConstructorHelpers::FObjectFinderOptional<UMaterial> Color_2;
        ConstructorHelpers::FObjectFinderOptional<UMaterial> Color_3;
        ConstructorHelpers::FObjectFinderOptional<UMaterial> Color_4;
        FConstructorStatics()
            : Color_0(TEXT("Material'/Game/Blueprints/bmadera.bmadera'"))
            , Color_1(TEXT("Material'/Game/Blueprints/bmetal.bmetal'"))
            , Color_2(TEXT("Material'/Game/Blueprints/bhielo.bhielo'"))
            , Color_3(TEXT("Material'/Game/Blueprints/btnt.btnt'"))
            , Color_4(TEXT("Material'/Game/Blueprints/bpiedra.bpiedra'"))
        {
        }
    };
    static FConstructorStatics ConstructorStatics;
    Colors.Add(ConstructorStatics.Color_0.Get());
    Colors.Add(ConstructorStatics.Color_1.Get());
    Colors.Add(ConstructorStatics.Color_2.Get());
    Colors.Add(ConstructorStatics.Color_3.Get());
    Colors.Add(ConstructorStatics.Color_4.Get());
}

// Called when the game starts or when spawned
void APiezaRaraDer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APiezaRaraDer::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

}

void APiezaRaraDer::SpawnBlocksDer()
{
    std::vector<std::vector<std::pair<float, float>>> Shapes =
    {
        {{-20.0, 0.0}, {-10.0, 0.0}, {0.0, 0.0}, {10.0, 0.0}, {20.0, 0.0}, {30.0, 0.0}},
        {{-10.0, 0.0}, {0.0, 0.0}, {10.0, 0.0}, {20.0, 0.0}, {30.0, 0.0}, {40.0, 0.0}},
        {{-20.0, 0.0}, {-10.0, 0.0}, {0.0, 0.0}, {0.0, 10.0}, {0.0, 20.0}, {0.0, 30.0}},
        {{0.0, 10.0}, {0.0, 0.0}, {10.0, 0.0}, {20.0, 0.0}, {30.0, 0.0}, {40.0, 0.0}},
        {{-10.0, -10.0}, {0.0, -10.0}, {0.0, 0.0}, {10.0, 0.0}, {20.0, 0.0}, {30.0, 0.0}},
        {{-10.0, 0.0}, {0.0, 0.0}, {0.0, 10.0}, {10.0, 0.0}, {20.0, 0.0}, {30.0, 0.0}},
        {{-10.0, 0.0}, {0.0, 0.0}, {0.0, -10.0}, {10.0, -10.0}, {20.0, -10.0}, {30.0, -10.0}},
    };

    const int Index = FMath::RandRange(0, Shapes.size() - 1);
    UE_LOG(LogTemp, Warning, TEXT("index=%d"), Index);
    const std::vector<std::pair<float, float>>& YZs = Shapes[Index];
    for (auto&& YZ : YZs)
    {
        FRotator Rotation(0.0, 0.0, 0.0);
        int32 BlockIndex = FMath::RandRange(0, 4); // Generar un índice aleatorio para seleccionar un bloque
        ABlock* B;
        switch (BlockIndex)
        {
        case 0:
            B = GetWorld()->SpawnActor<ABloqueMadera>(this->GetActorLocation(), Rotation);
            B->Mesh->SetMaterial(1, Colors[0]);
            break;
        case 1:
            B = GetWorld()->SpawnActor<ABloqueMetal>(this->GetActorLocation(), Rotation);
            B->Mesh->SetMaterial(1, Colors[1]);
            break;
        case 2:
            B = GetWorld()->SpawnActor<ABloqueHielo>(this->GetActorLocation(), Rotation);
            B->Mesh->SetMaterial(1, Colors[2]);
            break;
        case 3:
            B = GetWorld()->SpawnActor<ABloqueExplosivo>(this->GetActorLocation(), Rotation);
            B->Mesh->SetMaterial(1, Colors[3]);
            break;
        case 4:
            B = GetWorld()->SpawnActor<ABloquePiedra>(this->GetActorLocation(), Rotation);
            B->Mesh->SetMaterial(1, Colors[4]);
            break;
        default:
            B = GetWorld()->SpawnActor<ABlock>(this->GetActorLocation(), Rotation);
            break;
        }
        Blocks.Add(B);
        B->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
        B->SetActorRelativeLocation(FVector(-20.0, YZ.first + 120.0, YZ.second + 20.0));
    }
}

