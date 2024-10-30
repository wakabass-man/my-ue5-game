#include "BaseCharacter.h"
#include "MyAbilitySystemComponent.h"

// Fill out your copyright notice in the Description page of Project Settings.

// Sets default values
ABaseCharacter::ABaseCharacter(const class FObjectInitializer& Initializer)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DeadTag = FGameplayTag::RequestGameplayTag(FName("State.Dead"));
	RemoveEffectOnDeathTag = FGameplayTag::RequestGameplayTag(FName("State.RemoveEffectOnDeath"));
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

UAbilitySystemComponent* ABaseCharacter::GetAbilitySystemComponent() const
{
	return nullptr;
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

bool ABaseCharacter::IsAlive() const
{
	return GetHealth() > 0.f;
}

int32 ABaseCharacter::GetAbilityLevel(AbilityID Ability) const
{
	return 1;
}

void ABaseCharacter::RemoveAbilities()
{
	if (GetLocalRole() != ROLE_Authority || !ASC || !ASC->CharacterAbilityGiven)
	{
		return;
	}

	TArray<FGameplayAbilitySpecHandle> ArrayOfAbilityToRemove = {};
	for (const auto& e : ASC->GetActivatableAbilities())
	{
		if ((e.SourceObject == this) && AbilityArray.Contains(e.Ability->GetClass()))
		{
			ArrayOfAbilityToRemove.Add(e.Handle);
		}
	}

	for (auto& e : ArrayOfAbilityToRemove)
	{
		ASC->ClearAbility(e);
	}

	ASC->CharacterAbilityGiven = false;
}

void ABaseCharacter::Die()
{
}

void ABaseCharacter::FinishDying()
{
}

float ABaseCharacter::GetMaxHealth() const
{
	return 0.0f;
}

float ABaseCharacter::GetHealth() const
{
	return 0.0f;
}

void ABaseCharacter::AddAbility() const
{
}

void ABaseCharacter::InitAttribute() const
{
}

void ABaseCharacter::AddDefaultEffect() const
{
}

void ABaseCharacter::SetHealth(float Health) const
{
}

void ABaseCharacter::SetMaxHealth(float MaxHealth) const
{
}