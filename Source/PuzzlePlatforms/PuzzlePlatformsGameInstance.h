// Fill out your copfyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PuzzlePlatformsGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UPuzzlePlatformsGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UPuzzlePlatformsGameInstance(const FObjectInitializer& ObjectInitializer);
	
	virtual void Init() override;
	
	/**
	 * Host exec that execute in console.
	 * @param Comment
	 * @return Comment
	 */
	UFUNCTION(Exec)
	void Host();

	/**
	* Join exec that execute in console.
	* @param Comment
	* @return Comment
	*/
	UFUNCTION(Exec)
	void Join(const FString& Address);

	/**
	* Load Menu
	* @param Comment
	* @return Comment
	*/
	UFUNCTION(BlueprintCallable)
	void LoadMenu();

private:
	TSubclassOf<class UUserWidget> MenuClass;
};
