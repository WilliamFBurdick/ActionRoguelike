// Fill out your copyright notice in the Description page of Project Settings.


#include "RLTargetDummy.h"
#include "Components/StaticMeshComponent.h"
#include "RLAttributeComponent.h"

// Sets default values
ARLTargetDummy::ARLTargetDummy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("Mesh Comp");
	RootComponent = MeshComp;

	AttributeComp = CreateDefaultSubobject<URLAttributeComponent>("Attribute Comp");
	AttributeComp->OnHealthChanged.AddDynamic(this, &ARLTargetDummy::OnHealthChanged);
}

void ARLTargetDummy::OnHealthChanged(AActor* InstigatorActor, URLAttributeComponent* OwningComp, float NewHealth, float Delta)
{
	if (Delta < 0)
	{
		MeshComp->SetScalarParameterValueOnMaterials("TimeToHit", GetWorld()->TimeSeconds);
	}
}
