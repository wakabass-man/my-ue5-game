// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "MyAbilitySystemComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FReceivedDamageDelegate, UMyAbilitySystemComponent*, ASC, float, UnmitigatedDamage, float, MitigatedDamage);

/**
 * 
 */
UCLASS()
class MYTEMPLERUN_API UMyAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
	
public:
	bool CharacterAbilityGiven = false;
	bool StartupEffectApplied = false;

public:

	// 데미지 처리 델리게이트에 특화된 구조체 
	// AddDynamic?
	// Broadcast() 사용하려고?
	// 유프로퍼티 지정자는 필요없?
	// 데미지 처리는 GE에서 하면 안되는지?
	FReceivedDamageDelegate DamageDelegate;

public:

	virtual void ReceiveDamage(UMyAbilitySystemComponent* ASC, float UnmitigatedDamage, float MitigatedDamage);
};
