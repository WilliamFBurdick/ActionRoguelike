// Fill out your copyright notice in the Description page of Project Settings.


#include "RLAttributeComponent.h"

// Sets default values for this component's properties
URLAttributeComponent::URLAttributeComponent()
{
	Health = 100;
	HealthMax = 100;
}

float URLAttributeComponent::GetMaxHealth() const
{
	return HealthMax;
}

bool URLAttributeComponent::IsAlive() const
{
	return Health > 0.0f;
}

bool URLAttributeComponent::IsFullHealth() const
{
	return Health == HealthMax;
}

bool URLAttributeComponent::ApplyHealthChange(AActor* InstigatorActor, float Delta)
{
	float OldHealth = Health;

	Health += Delta;
	Health = FMath::Clamp(Health, 0.0f, HealthMax);

	float ActualDelta = Health - OldHealth;
	OnHealthChanged.Broadcast(InstigatorActor, this, Health, ActualDelta);

	return ActualDelta != 0;
}

float URLAttributeComponent::GetHealth()
{
	return Health;
}

URLAttributeComponent* URLAttributeComponent::GetAttributes(AActor* FromActor)
{
	if (FromActor)
	{
		return Cast<URLAttributeComponent>(FromActor->GetComponentByClass(URLAttributeComponent::StaticClass()));
	}
	return nullptr;
}

bool URLAttributeComponent::IsActorAlive(AActor* Actor)
{
	URLAttributeComponent* AttributeComponent = GetAttributes(Actor);
	if (AttributeComponent)
	{
		return AttributeComponent->IsAlive();
	}
	return false;
}