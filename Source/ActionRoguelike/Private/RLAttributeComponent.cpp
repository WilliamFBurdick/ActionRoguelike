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

bool URLAttributeComponent::ApplyHealthChange(float Delta)
{
	Health += Delta;
	Health = FMath::Clamp(Health, 0.0f, HealthMax);
	OnHealthChanged.Broadcast(nullptr, this, Health, Delta);
	return true;
}

float URLAttributeComponent::GetHealth()
{
	return Health;
}