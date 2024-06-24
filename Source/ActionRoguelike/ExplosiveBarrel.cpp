// Fill out your copyright notice in the Description page of Project Settings.


#include "ExplosiveBarrel.h"
#include "PhysicsEngine/RadialForceComponent.h"

// Sets default values
AExplosiveBarrel::AExplosiveBarrel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	StaticMeshComp->OnComponentHit.AddDynamic(this, &AExplosiveBarrel::OnHit);
	RootComponent = StaticMeshComp;

	RadialForceComp = CreateDefaultSubobject<URadialForceComponent>("RadialForce");
	RadialForceComp->Radius = 700.0f;
	RadialForceComp->ForceStrength = 2000.0f;
	RadialForceComp->SetupAttachment(StaticMeshComp);

}

// Called when the game starts or when spawned
void AExplosiveBarrel::BeginPlay()
{
	Super::BeginPlay();
	
}

void AExplosiveBarrel::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	RadialForceComp->FireImpulse();
}

// Called every frame
void AExplosiveBarrel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

