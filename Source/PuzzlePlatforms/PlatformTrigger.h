// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlatformTrigger.generated.h"

UCLASS()
class PUZZLEPLATFORMS_API APlatformTrigger : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlatformTrigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	/**
	 * Trigger volume to trigger the platforms.
	 */
	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* TriggerVolume;

	/**
	 * Platforms that triggers
	 */
	UPROPERTY(EditAnywhere, Category = "MovingPlatforms")
	TArray<class AMovingPlatform*> MovingPlatforms;

	/**
	 * Callback function of OnComponentBeginOverlap
	 * @param Comment
	 * @return Comment
	 */
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, 
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	/**
	* Callback function of OnComponentEndOverlap
	* @param Comment
	* @return Comment
	*/
	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, 
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};
