// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "DashAbility.generated.h"

/**
 * 
 */
UCLASS()
class FLAREFORGE_API UDashAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	
	//Override the ActivateAbility method
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

	//UPROPERTY(EditAnywhere)
	//FVector DashDistance;

	UPROPERTY(EditAnywhere)
	float DashDistance = 5000.0f;
};
