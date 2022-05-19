// Fill out your copyright notice in the Description page of Project Settings.


#include "RandomMovementComponent.h"
#include "NaveAereaEnemiga.h"

// Sets default values
ANaveAereaEnemiga::ANaveAereaEnemiga()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO"));

	ShipMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	RootComponent = ShipMeshComponent;
	ShipMeshComponent->SetStaticMesh(ShipMesh.Object);
	RandMove = CreateDefaultSubobject<URandomMovementComponent>(TEXT("RandomMovement"));
}

// Called when the game starts or when spawned
void ANaveAereaEnemiga::BeginPlay()
{
	Super::BeginPlay();

	
}

// Called every frame
void ANaveAereaEnemiga::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



