#include "BaseCharacter.h"
#include "MyPlayerState.h"
#include "MyAbilitySystemComponent.h"
#include "MyAttributeSet.h"

// Fill out your copyright notice in the Description page of Project Settings.

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ASC = CreateDefaultSubobject<UMyAbilitySystemComponent>(TEXT("Ability System Component"));
	AttributeSet = CreateDefaultSubobject<UMyAttributeSet>(TEXT("Attribute Set"));

}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	/*DeadTag = FGameplayTag::RequestGameplayTag(FName("State.Dead"));
	RemoveEffectOnDeathTag = FGameplayTag::RequestGameplayTag(FName("State.RemoveEffectOnDeath"));*/
	
	ASC->SetIsReplicated(true);
	ASC->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	ASC->InitAbilityActorInfo(this, this);

	if (HasAuthority())
	{
		GiveDefaultAbilities();
		InitDefaultAttributes();
	}
	
	
}

UAbilitySystemComponent* ABaseCharacter::GetAbilitySystemComponent() const
{
	return ASC;
}

void ABaseCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	PlayerState = GetPlayerState<AMyPlayerState>();
	
	
}

void ABaseCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();


}

void ABaseCharacter::GiveDefaultAbilities()
{
	for (TSubclassOf<class UGameplayAbility> e : AbilityArray)
	{
		FGameplayAbilitySpec AbilitySpec(e, 1);
		ASC->GiveAbility(AbilitySpec);
	}
}

void ABaseCharacter::InitDefaultAttributes()
{
	if (DefaultAttriEffectArray.Num() > 0) 
	{
		auto ContextHandle = ASC->MakeEffectContext();
		ContextHandle.AddSourceObject(this);

		for (auto e : DefaultAttriEffectArray)
		{
			auto SpecHandle = ASC->MakeOutgoingSpec(e, 1, ContextHandle);

			//GE Àû¿ë
			ASC->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
		}
	}
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

//bool ABaseCharacter::IsAlive() const
//{
//	return GetHealth() > 0.f;
//}
//
//int32 ABaseCharacter::GetAbilityLevel(AbilityID Ability) const
//{
//	return 1;
//}
//
//void ABaseCharacter::RemoveAbilities()
//{
//	if (GetLocalRole() != ROLE_Authority || !ASC || !ASC->CharacterAbilityGiven)
//	{
//		return;
//	}
//
//	TArray<FGameplayAbilitySpecHandle> ArrayOfAbilityToRemove = {};
//	for (const auto& e : ASC->GetActivatableAbilities())
//	{
//		if ((e.SourceObject == this) && AbilityArray.Contains(e.Ability->GetClass()))
//		{
//			ArrayOfAbilityToRemove.Add(e.Handle);
//		}
//	}
//
//	for (auto& e : ArrayOfAbilityToRemove)
//	{
//		ASC->ClearAbility(e);
//	}
//
//	ASC->CharacterAbilityGiven = false;
//}
//
//void ABaseCharacter::Die()
//{
//}
//
//void ABaseCharacter::FinishDying()
//{
//}
//
//float ABaseCharacter::GetMaxHealth() const
//{
//	return 0.0f;
//}
//
//float ABaseCharacter::GetHealth() const
//{
//	return 0.0f;
//}
//
//void ABaseCharacter::AddAbility() const
//{
//}
//
//void ABaseCharacter::InitAttribute() const
//{
//}
//
//void ABaseCharacter::AddDefaultEffect() const
//{
//}
//
//void ABaseCharacter::SetHealth(float Health) const
//{
//}
//
//void ABaseCharacter::SetMaxHealth(float MaxHealth) const
//{
//}