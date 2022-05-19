// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "NaveNodriza.generated.h"

UCLASS()
class STARFIGHTER_API ANaveNodriza : public APawn
{
	GENERATED_BODY()

		UPROPERTY(Category = Mesh, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* ShipMeshComponent;
public:
	// Sets default values for this pawn's properties
	ANaveNodriza();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, Category = "Spawing")
		class UBoxComponent* WhereToSpawn;

	UPROPERTY(EditAnywhere, Category = "Spawning")
		TArray<TSubclassOf<AActor>> SpawnClasses;

	float NextSpawnCoolDown = 2.0f;
	float SpawnCoolDown = 0.0f;
};
