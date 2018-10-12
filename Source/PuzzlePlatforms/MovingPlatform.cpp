// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"


AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();


}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Role == ROLE_Authority)
	{
		FVector ActorLocation = GetActorLocation();
		ActorLocation += FVector(Speed * DeltaTime, 0, 0);
		SetActorLocation(ActorLocation);

		// UE_LOG(LogTemp, Warning, TEXT("I'm in Server. My Role is %s ...."), Role);
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("I'm in Client."));
	}
}
