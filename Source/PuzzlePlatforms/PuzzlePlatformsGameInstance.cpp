// Fill out your copyright notice in the Description page of Project Settings.

#include "PuzzlePlatformsGameInstance.h"




UPuzzlePlatformsGameInstance::UPuzzlePlatformsGameInstance(const FObjectInitializer& ObjectInitializer) 
{
	UE_LOG(LogTemp, Warning, TEXT("Puzzle Platform Game Instance Construcor(). "));
}

void UPuzzlePlatformsGameInstance::Init() 
{
	UE_LOG(LogTemp, Warning, TEXT("Puzzle Platform Game Instance Init(). "));
}

void UPuzzlePlatformsGameInstance::Host() 
{
	UE_LOG(LogTemp, Warning, TEXT("This is Host Func Exec called. "));

	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("Hosting... "));

	UWorld* CurrentWorld = GetWorld();
	if (CurrentWorld)
	{
		CurrentWorld->ServerTravel("/Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap?listen");
	}
}

void UPuzzlePlatformsGameInstance::Join(const FString& Address)
{
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, FString::Printf(TEXT("Join %s"), *Address));

	APlayerController* PC = GetFirstLocalPlayerController();
	if (PC)
	{
		PC->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
	}
}
