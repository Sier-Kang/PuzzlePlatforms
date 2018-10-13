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
		// Actor's Replication
		SetReplicates(true);
		SetReplicateMovement(true);

		// Move Props
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
		float TotalLength = (WorldEndLocation - WorldStartLocation).Size();
		float CurrentLength = (WorldEndLocation - ActorLocation).Size();
		FVector MoveDirection = (WorldEndLocation - WorldStartLocation).GetSafeNormal();

		if (CurrentLength >= TotalLength)
		{
			FVector SwapLocation = WorldStartLocation;
			WorldStartLocation = WorldEndLocation;
			WorldEndLocation = SwapLocation;
		}
		else {
			ActorLocation += Speed * DeltaTime * MoveDirection;
			SetActorLocation(ActorLocation);
		}

		// UE_LOG(LogTemp, Warning, TEXT("I'm in Server. My Role is ROLE_Authority"));
	}
}

void AMovingPlatform::AddActiveTrigger() 
{

}

void AMovingPlatform::RemoveActiveTrigger() 
{

}
