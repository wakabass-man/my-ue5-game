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

	// ������ ó�� ��������Ʈ�� Ưȭ�� ����ü 
	// AddDynamic?
	// Broadcast() ����Ϸ���?
	// ��������Ƽ �����ڴ� �ʿ��?
	// ������ ó���� GE���� �ϸ� �ȵǴ���?
	FReceivedDamageDelegate DamageDelegate;

public:

	virtual void ReceiveDamage(UMyAbilitySystemComponent* ASC, float UnmitigatedDamage, float MitigatedDamage);
};
