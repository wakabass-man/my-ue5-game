// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAbilitySystemComponent.h"

void UMyAbilitySystemComponent::ReceiveDamage(UMyAbilitySystemComponent* ASC, float UnmitigatedDamage, float MitigatedDamage)
{
	// ���� ���Ҷ� ��ϵ� ��� �Լ����� �� ���� ȣ��
	DamageDelegate.Broadcast(ASC, UnmitigatedDamage, MitigatedDamage);
}