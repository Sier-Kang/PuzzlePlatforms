// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:
	AMovingPlatform();

	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;

	/**
	 * Speed that the box moves.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MoveInfo")
	float Speed = 20.0f;

	/**
	 * Actor's location.
	 */
	UPROPERTY(EditAnywhere, Category = "MoveInfo", meta = (MakeEditWidget = true))
	FVector TargetLocation;

private:
	FVector WorldStartLocation;
	FVector WorldEndLocation;
};
