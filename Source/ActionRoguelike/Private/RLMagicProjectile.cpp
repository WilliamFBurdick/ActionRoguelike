// Fill out your copyright notice in the Description page of Project Settings.


#include "RLMagicProjectile.h"
#include "Components/SphereComponent.h"
#include "Components/AudioComponent.h"
#include "RLAttributeComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ARLMagicProjectile::ARLMagicProjectile()
	:AProjectileBase()
{

	SphereComp->SetSphereRadius(20.0f);
	SphereComp->OnComponentBeginOverlap.AddDynamic(this, &ARLMagicProjectile::OnActorOverlap);

	SoundComp = CreateDefaultSubobject<UAudioComponent>("SoundComp");
	SoundComp->SetupAttachment(SphereComp);

	DamageAmount = 20.0f;
}

void ARLMagicProjectile::OnActorOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != GetInstigator())
	{
		URLAttributeComponent* AttributeComp = Cast<URLAttributeComponent>(OtherActor->GetComponentByClass(URLAttributeComponent::StaticClass()));
		if (AttributeComp)
		{
			AttributeComp->ApplyHealthChange(-DamageAmount);
		}


		if (ensure(ImpactSound))
		{
			UGameplayStatics::PlaySoundAtLocation(this, ImpactSound, GetActorLocation());
		}
		Destroy();
	}
}
