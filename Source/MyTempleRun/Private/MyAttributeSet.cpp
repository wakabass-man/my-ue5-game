// Fill out your copyright notice in the Description page of Project Settings.

#include "MyAttributeSet.h"
#include "Net/UnrealNetwork.h"
#include "GameplayEffect.h"
#include "GameplayEffectExtension.h"

UMyAttributeSet::UMyAttributeSet()
{
	Health = 100.f;
	MaxHealth = 100.f;
	Damage = 10.f;
	Armor = 0.f;
	Strength = 0.f;
	
	Pliability = 0.f;
	XP = 0.f;
	Level = 1.f;
	SP = 0.f;
	Money = 0.f;
}

void UMyAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);
}

void UMyAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	FGameplayEffectContextHandle Context = Data.EffectSpec.GetContext();
	UAbilitySystemComponent* ASC = Context.GetOriginalInstigatorAbilitySystemComponent();
	const FGameplayTagContainer& SourceTagContainer = *Data.EffectSpec.CapturedSourceTags.GetAggregatedTags();
	FGameplayTagContainer TagContainer;
	Data.EffectSpec.GetAllAssetTags(TagContainer);

	//이미 이펙트에 의해서 체력이 변경된 상태?
	//어트리뷰트 초기화는 따로 안하는지
	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp(GetHealth(), 0.f, GetMaxHealth()));
		/*HealthChangeDelegate.Broadcast(GetHealth(), Data.EffectSpec.StackCount);*/
	}
	else if (Data.EvaluatedData.Attribute == GetMaxHealthAttribute())
	{
		SetMaxHealth(GetMaxHealth());
	}
	else if (Data.EvaluatedData.Attribute == GetDamageAttribute())
	{
		SetDamage(GetDamage());
	}
	else if (Data.EvaluatedData.Attribute == GetArmorAttribute())
	{
		SetArmor(GetArmor());
	}
	else if (Data.EvaluatedData.Attribute == GetStrengthAttribute())
	{
		SetStrength(GetStrength());
	}
	else if (Data.EvaluatedData.Attribute == GetPliabilityAttribute())
	{
		SetPliability(GetPliability());
	}
	else if (Data.EvaluatedData.Attribute == GetXPAttribute())
	{
		SetXP(GetXP());
	}
	else if (Data.EvaluatedData.Attribute == GetLevelAttribute())
	{
		SetLevel(GetLevel());
	}
	else if (Data.EvaluatedData.Attribute == GetSPAttribute())
	{
		SetSP(GetSP());
	}
	else if (Data.EvaluatedData.Attribute == GetMoneyAttribute())
	{
		SetMoney(GetMoney());
	}
}

void UMyAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UMyAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UMyAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UMyAttributeSet, Armor, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UMyAttributeSet, Damage, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UMyAttributeSet, Strength, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UMyAttributeSet, Pliability, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UMyAttributeSet, XP, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UMyAttributeSet, Level, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UMyAttributeSet, SP, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UMyAttributeSet, Money, COND_None, REPNOTIFY_Always);
}

void UMyAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMyAttributeSet, Health, OldHealth);
}

void UMyAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMyAttributeSet, MaxHealth, OldMaxHealth);
}

void UMyAttributeSet::OnRep_Damage(const FGameplayAttributeData& OldDamage)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMyAttributeSet, Damage, OldDamage);
}

void UMyAttributeSet::OnRep_Armor(const FGameplayAttributeData& OldArmor)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMyAttributeSet, Armor, OldArmor);
}

void UMyAttributeSet::OnRep_Strength(const FGameplayAttributeData& OldStrength)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMyAttributeSet, Strength, OldStrength);
}

void UMyAttributeSet::OnRep_Pliability(const FGameplayAttributeData& OldPliability)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMyAttributeSet, Pliability, OldPliability);
}

void UMyAttributeSet::OnRep_XP(const FGameplayAttributeData& OldXP)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMyAttributeSet, XP, OldXP);
}

void UMyAttributeSet::OnRep_Level(const FGameplayAttributeData& OldLevel)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMyAttributeSet, Level, OldLevel);
}

void UMyAttributeSet::OnRep_SP(const FGameplayAttributeData& OldSP)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMyAttributeSet, SP, OldSP);
}

void UMyAttributeSet::OnRep_Money(const FGameplayAttributeData& OldMoney)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMyAttributeSet, Money, OldMoney);
}