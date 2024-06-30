// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectileBase.h"
#include "RLDashProjectile.generated.h"

UCLASS()
class ACTIONROGUELIKE_API ARLDashProjectile : public AProjectileBase
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARLDashProjectile();

protected:

	UPROPERTY(EditDefaultsOnly, Category="Teleport")
	float TeleportDelay;

	UPROPERTY(EditDefaultsOnly, Category="Teleport")
	float DetonateDelay;

	// Handle to cancel timer if something hit
	FTimerHandle TimerHandle_DelayedDetonate;

	virtual void Explode_Implementation() override;

	void TeleportInstigator();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
