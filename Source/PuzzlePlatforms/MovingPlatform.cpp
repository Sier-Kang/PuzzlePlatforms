// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"
#include "UnrealNetwork.h"


AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority()) 
	{
		SetReplicates(true);
		SetReplicateMovement(true);

		WorldStartLocation = GetActorLocation();
		WorldEndLocation = GetTransform().TransformPosition(TargetLocation);
	}
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (HasAuthority())
	{
		FVector ActorLocation = GetActorLocation();
		float CurrentLength = (WorldEndLocation - ActorLocation).Size();
		float TotalLength = (WorldStartLocation - WorldEndLocation).Size();
		FVector MoveDirection = WorldEndLocation - WorldStartLocation;

		if (CurrentLength > TotalLength)
		{
			FVector SwapLocation = WorldStartLocation;
			WorldStartLocation = WorldEndLocation;
			WorldEndLocation = SwapLocation;
		}
		else {
			ActorLocation += Speed * DeltaTime * MoveDirection.GetSafeNormal();
			SetActorLocation(ActorLocation);
		}

		// UE_LOG(LogTemp, Warning, TEXT("I'm in Server. My Role is ROLE_Authority"));
	}
}
