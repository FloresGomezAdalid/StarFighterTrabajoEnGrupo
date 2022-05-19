// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveNodriza.h"
#include "Components/BoxComponent.h"
#include "NaveAereaEnemiga.h"

// Sets default values
ANaveNodriza::ANaveNodriza()
{

	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO"));
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	ShipMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	RootComponent = ShipMeshComponent;
	ShipMeshComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	ShipMeshComponent->SetStaticMesh(ShipMesh.Object);
	WhereToSpawn = CreateDefaultSubobject<UBoxComponent>(TEXT("Spawn"));


}

// Called when the game starts or when spawned
void ANaveNodriza::BeginPlay()
{
	Super::BeginPlay();
	
	SpawnClasses.Add(ANaveAereaEnemiga::StaticClass());
	UE_LOG(LogTemp, Warning, TEXT("Box: %s"), *WhereToSpawn->GetScaledBoxExtent().ToString());
}

// Called every frame
void ANaveNodriza::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


    if (SpawnClasses.Num() <= 0)
    {
        return;
    }
    const int Index = FMath::RandRange(0, SpawnClasses.Num() - 1);

    SpawnCoolDown += DeltaTime;
    if (SpawnCoolDown >= NextSpawnCoolDown)
    {
        FVector Location = WhereToSpawn->GetComponentLocation();
        float Y = WhereToSpawn->GetScaledBoxExtent().Y;
        Location.Y = FMath::RandRange(Location.Y - Y, Location.Y + Y);
        UE_LOG(LogTemp, Warning, TEXT("Should Spawn at: %s"), *Location.ToString());
        SpawnCoolDown = 30.0f;
        FRotator Rotation = GetActorRotation();
        Rotation.Pitch = 180.0f;
        GetWorld()->SpawnActor(SpawnClasses[Index], &Location, &Rotation);

    }
}

// Called to bind functionality to input
void ANaveNodriza::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

