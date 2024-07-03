// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RLGameplayInterface.h"
#include "RLPowerupActor.generated.h"

class USphereComponent;

UCLASS()
class ACTIONROGUELIKE_API ARLPowerupActor : public AActor, public IRLGameplayInterface
{
	GENERATED_BODY()

	virtual void Interact_Implementation(APawn* InstigatorPawn);
	
public:	
	// Sets default values for this actor's properties
	ARLPowerupActor();

protected:

	UPROPERTY(VisibleAnywhere, Category="Components")
	USphereComponent* SphereComp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Powerup")
	float RespawnTime;

	UFUNCTION()
	void ShowPickup();

	UFUNCTION()
	void HideAndCooldownPowerup();

	UFUNCTION()
	void SetPowerupState(bool bNewIsActive);

	FTimerHandle TimerHandle_RespawnTimer;
};
