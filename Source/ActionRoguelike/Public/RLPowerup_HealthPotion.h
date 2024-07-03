// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RLPowerupActor.h"
#include "RLPowerup_HealthPotion.generated.h"

class UStaticMeshComponent;

/**
 * 
 */
UCLASS()
class ACTIONROGUELIKE_API ARLPowerup_HealthPotion : public ARLPowerupActor
{
	GENERATED_BODY()
	
	ARLPowerup_HealthPotion();

	virtual void Interact_Implementation(APawn* InstigatorPawn) override;

protected:
	
	UPROPERTY(VisibleAnywhere, Category="Components")
	UStaticMeshComponent* MeshComp;

};
