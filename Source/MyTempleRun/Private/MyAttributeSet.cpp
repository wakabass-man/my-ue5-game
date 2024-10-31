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

	/*InitHealth(100.f);
	InitMaxHealth(100.f);
	InitDamage(10.f);
	InitArmor(0.f);
	InitStrength(0.f);

	InitPliability(0.f);
	InitXP(0.f);
	InitLevel(1.f);
	InitSP(0.f);
	InitMoney(0.f);*/
}

void UMyAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxHealth());
	}
}

void UMyAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	FGameplayEffectContextHandle Context = Data.EffectSpec.GetContext();
	UAbilitySystemComponent* ASC = Context.GetOriginalInstigatorAbilitySystemComponent();
	const FGameplayTagContainer& SourceTagContainer = *Data.EffectSpec.CapturedSourceTags.GetAggregatedTags();
	FGameplayTagContainer TagContainer;
	Data.EffectSpec.GetAllAssetTags(TagContainer);

	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(GetHealth());
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