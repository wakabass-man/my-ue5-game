// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAbilitySystemComponent.h"

void UMyAbilitySystemComponent::ReceiveDamage(UMyAbilitySystemComponent* ASC, float UnmitigatedDamage, float MitigatedDamage)
{
	// 값이 변할때 등록된 모든 함수들을 한 번에 호출
	DamageDelegate.Broadcast(ASC, UnmitigatedDamage, MitigatedDamage);
}