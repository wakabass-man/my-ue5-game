// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
//#include "MyTempleRun/MyTempleRun.h"
//#include "GameplayTagContainer.h"
#include "BaseCharacter.generated.h"

//DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParams(FCharacterDiedDelegate, ABaseCharacter*, Character);

UCLASS()
class MYTEMPLERUN_API ABaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

public:
	class UMyAbilitySystemComponent* ASC;
	class UMyAttributeSet* AttributeSet;
	class AMyPlayerState* PlayerState;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My|Ability")
	TArray<TSubclassOf<class UGameplayAbility>> AbilityArray;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My|Effect")
	TArray<TSubclassOf<class UGameplayEffect>> DefaultAttriEffectArray;

	/*UPROPERTY(BlueprintAssignable, Category = "My|Delegate Structure")
	FCharacterDiedDelegate DieDelegate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My|Tag")
	FGameplayTag DeadTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My|Tag")
	FGameplayTag RemoveEffectOnDeathTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My|Text")
	FText CharacterName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My|Animation")
	UAnimMontage* Montage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My|Effect")
	TSubclassOf<class UGameplayEffect> DefaultEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My|Effect")
	TArray<TSubclassOf<class UGameplayEffect>> DefaultEffectArray;*/

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	virtual void PossessedBy(AController* NewController) override;

	virtual void OnRep_PlayerState() override;

	void GiveDefaultAbilities();

	void InitDefaultAttributes();

	inline class UMyAttributeSet* GetAttributeSet() const { return AttributeSet; }

	/*UFUNCTION(BlueprintCallable)
	virtual bool IsAlive() const;

	UFUNCTION(BlueprintCallable)
	virtual int32 GetAbilityLevel(AbilityID Ability) const;

	UFUNCTION(BlueprintCallable)
	virtual void RemoveAbilities();

	UFUNCTION(BlueprintCallable)
	virtual void Die();

	UFUNCTION(BlueprintCallable)
	virtual void FinishDying();

	UFUNCTION(BlueprintCallable)
	virtual float GetMaxHealth() const;

	UFUNCTION(BlueprintCallable)
	virtual float GetHealth() const;

	UFUNCTION(BlueprintCallable)
	virtual void AddAbility() const;
	
	UFUNCTION(BlueprintCallable)
	virtual void InitAttribute() const;

	UFUNCTION(BlueprintCallable)
	virtual void AddDefaultEffect() const;

	UFUNCTION(BlueprintCallable)
	virtual void SetHealth(float Health) const;

	UFUNCTION(BlueprintCallable)
	virtual void SetMaxHealth(float MaxHealth) const;*/
};