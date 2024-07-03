// Fill out your copyright notice in the Description page of Project Settings.


#include "RLPowerupActor.h"
#include "Components/SphereComponent.h"


// Sets default values
ARLPowerupActor::ARLPowerupActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComp = CreateDefaultSubobject<USphereComponent>("SphereComp");
	SphereComp->SetCollisionProfileName("Powerup");
	RootComponent = SphereComp;

	RespawnTime = 10.0f;

}

void ARLPowerupActor::Interact_Implementation(APawn* InstigatorPawn)
{
	// Logic in derived class
}

void ARLPowerupActor::ShowPickup()
{
	SetPowerupState(true);
}

void ARLPowerupActor::HideAndCooldownPowerup()
{
	SetPowerupState(false);
	GetWorldTimerManager().SetTimer(TimerHandle_RespawnTimer, this, &ARLPowerupActor::ShowPickup, RespawnTime);
}

void ARLPowerupActor::SetPowerupState(bool bNewIsActive)
{
	SetActorEnableCollision(bNewIsActive);
	// Set visibility on root and all children
	RootComponent->SetVisibility(bNewIsActive, true);
}
