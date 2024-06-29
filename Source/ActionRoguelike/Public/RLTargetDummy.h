// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RLTargetDummy.generated.h"

class URLAttributeComponent;
class UStaticMeshComponent;

UCLASS()
class ACTIONROGUELIKE_API ARLTargetDummy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARLTargetDummy();

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	URLAttributeComponent* AttributeComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	UStaticMeshComponent* MeshComp;

	UFUNCTION()
	void OnHealthChanged(AActor* InstigatorActor, URLAttributeComponent* OwningComp, float NewHealth, float Delta);

public:	

};
