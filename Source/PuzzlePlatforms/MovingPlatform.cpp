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
		WorldTargetLocation = GetTransform().TransformPosition(TargetLocation);
	}
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (ActiveTriggers > 0)
	{
		if (HasAuthority())
		{
			FVector ActorLocation = GetActorLocation();
			float JourneyLength = (WorldTargetLocation - WorldStartLocation).Size();
			float JourneyTravelled = (WorldStartLocation - ActorLocation).Size();
			FVector MoveDirection = (WorldTargetLocation - WorldStartLocation).GetSafeNormal();

			if (JourneyTravelled >= JourneyLength)
			{
				FVector SwapLocation = WorldStartLocation;
				WorldStartLocation = WorldTargetLocation;
				WorldTargetLocation = SwapLocation;
			}
			else {
				ActorLocation += Speed * DeltaTime * MoveDirection;
				SetActorLocation(ActorLocation);
			}

			// UE_LOG(LogTemp, Warning, TEXT("I'm in Server. My Role is ROLE_Authority"));
		}
	}
}

void AMovingPlatform::AddActiveTrigger() 
{
	ActiveTriggers++;
}

void AMovingPlatform::RemoveActiveTrigger() 
{
	if (ActiveTriggers > 0)
	{
		ActiveTriggers--;
	}
}
