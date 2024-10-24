// Fill out your copyright notice in the Description page of Project Settings.

#include "MyAttributeSet.h"
#include "Net/UnrealNetwork.h"

UMyAttributeSet::UMyAttributeSet()
{

}


void UMyAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UMyAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UMyAttributeSet, Strength, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UMyAttributeSet, Pliability, COND_None, REPNOTIFY_Always);
}


void UMyAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMyAttributeSet, Health, OldHealth);
}

void UMyAttributeSet::OnRep_Strength(const FGameplayAttributeData& OldStrength)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMyAttributeSet, Strength, OldStrength);
}

void UMyAttributeSet::OnRep_Pliability(const FGameplayAttributeData& OldPliability)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMyAttributeSet, Pliability, OldPliability);
}
