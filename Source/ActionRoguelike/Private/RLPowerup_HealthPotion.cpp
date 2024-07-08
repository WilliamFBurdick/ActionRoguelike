// Fill out your copyright notice in the Description page of Project Settings.


#include "RLPowerup_HealthPotion.h"
#include "RLAttributeComponent.h"

ARLPowerup_HealthPotion::ARLPowerup_HealthPotion()
{
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("MeshComp");
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	MeshComp->SetupAttachment(RootComponent);
}

void ARLPowerup_HealthPotion::Interact_Implementation(APawn* InstigatorPawn)
{
	if (!ensure(InstigatorPawn))
	{
		return;
	}

	URLAttributeComponent* AttributeComp = URLAttributeComponent::GetAttributes(InstigatorPawn);
	if (ensure(AttributeComp) && !AttributeComp->IsFullHealth())
	{
		if (AttributeComp->ApplyHealthChange(this, AttributeComp->GetMaxHealth()))
		{
			HideAndCooldownPowerup();
		}
	}
}
