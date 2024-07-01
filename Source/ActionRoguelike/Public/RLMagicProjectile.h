// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectileBase.h"
#include "RLMagicProjectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;
class UParticleSystemComponent;
class UAudioComponent;
class USoundWave;

UCLASS()
class ACTIONROGUELIKE_API ARLMagicProjectile : public AProjectileBase
{
	GENERATED_BODY()
public:	
	// Sets default values for this actor's properties
	ARLMagicProjectile();

protected:

	UPROPERTY(EditDefaultsOnly, Category="Damage")
	float DamageAmount;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	UAudioComponent* SoundComp;

	UPROPERTY(EditDefaultsOnly, Category="Sound")
	USoundWave* ImpactSound;

	UFUNCTION()
	void OnActorOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
