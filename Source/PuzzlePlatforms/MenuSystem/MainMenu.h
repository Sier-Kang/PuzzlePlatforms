// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual bool Initialize() override;

private:
	/**
	* Host Button
	*/
	UPROPERTY(meta = (BindWidget))
	class UButton* Btn_Host;

	/**
	* Join Button
	*/
	UPROPERTY(meta = (BindWidget))
	class UButton* Btn_Join;

	/**
	 * Btn_Host button clicked event.
	 * @param  
	 * @return  
	 */
	UFUNCTION()
	void HostServer();

};
