// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RandomMovementComponent.h"
#include "GameFramework/Pawn.h"
#include "NaveAereaEnemiga.generated.h"

UCLASS()
class STARFIGHTER_API ANaveAereaEnemiga : public APawn
{
	GENERATED_BODY()

	UPROPERTY(Category = Mesh, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* ShipMeshComponent;

public:
	// Sets default values for this pawn's properties
	ANaveAereaEnemiga();

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
		class URandomMovementComponent* RandMove;

};
