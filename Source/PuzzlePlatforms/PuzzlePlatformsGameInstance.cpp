// Fill out your copyright notice in the Description page of Project Settings.

#include "PuzzlePlatformsGameInstance.h"
#include "PlatformTrigger.h"
#include "ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"


UPuzzlePlatformsGameInstance::UPuzzlePlatformsGameInstance(const FObjectInitializer& ObjectInitializer) 
{
	UE_LOG(LogTemp, Warning, TEXT("Puzzle Platform Game Instance Construcor(). "));

	// set default pawn class to our Blueprinted character
	ConstructorHelpers::FClassFinder<UUserWidget> MenuBPClass(TEXT("/Game/MenuSystem/MainMenu"));
	if (MenuBPClass.Class != NULL)
	{
		MenuClass = MenuBPClass.Class;

		UE_LOG(LogTemp, Warning, TEXT("Finder Class name is %s."), *MenuClass->GetName());
	}
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

void UPuzzlePlatformsGameInstance::LoadMenu() 
{
	if (!ensure(MenuClass != nullptr)) return;

	UUserWidget* Menu = CreateWidget<UUserWidget>(this, MenuClass);

	// Ensure pointer not null
	if (!ensure(Menu != nullptr)) return;

	Menu->AddToViewport();

	APlayerController* PC = GetFirstLocalPlayerController();
	// Ensure pointer not null
	if (!ensure(PC != nullptr)) return;

	FInputModeUIOnly InputModeData;
	InputModeData.SetWidgetToFocus(Menu->TakeWidget());
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

	PC->SetInputMode(InputModeData);
	PC->bShowMouseCursor = true;
}
