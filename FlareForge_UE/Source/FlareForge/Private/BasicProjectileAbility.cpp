// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicProjectileAbility.h"
#include "GameFramework/Character.h"
#include "LucasAbilitySystemComponent.h"
#include "FiringOffset.h"
#include "Kismet/GameplayStatics.h"

void UBasicProjectileAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	if (const AActor* Actor = GetAvatarActorFromActorInfo())
	{
		if (const ACharacter* Character = Cast<ACharacter>(Actor))
		{
			const FVector SpawnProjectileLocation = Character->GetComponentByClass<UFiringOffset>()->GetComponentLocation();
			const FRotator CurrentRotation = Character->GetActorRotation();
			BasicProjectileAbility(SpawnProjectileLocation, CurrentRotation);
			BasicProjectile->PlayerSpawningRootComponent(Character->GetRootComponent());
		}
	}

	CommitAbilityCooldown(Handle, ActorInfo, ActivationInfo, true, nullptr);
	
	// End the ability
	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}

void UBasicProjectileAbility::BasicProjectileAbility_Implementation(const FVector SpawnProjectileLocation, const FRotator CurrentRotation)
{
	const FActorSpawnParameters SpawnParameters;
	BasicProjectile = GetWorld()->SpawnActor<ABasicProjectile>(BasicProjectileBlueprint, SpawnProjectileLocation, CurrentRotation, SpawnParameters);
}
