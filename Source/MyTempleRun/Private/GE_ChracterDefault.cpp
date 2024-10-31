// Fill out your copyright notice in the Description page of Project Settings.


#include "GE_ChracterDefault.h"
#include "MyAttributeSet.h"

UGE_ChracterDefault::UGE_ChracterDefault()
{
	DurationPolicy = EGameplayEffectDurationType::Instant;

    FGameplayModifierInfo ModifierInfo = {};
    ModifierInfo.Attribute = UMyAttributeSet::GetMaxHealthAttribute();
    ModifierInfo.ModifierOp = EGameplayModOp::Override;
    ModifierInfo.ModifierMagnitude = FGameplayEffectModifierMagnitude(100.f);
    Modifiers.Add(ModifierInfo);
    ModifierInfo = {};
    ModifierInfo.Attribute = UMyAttributeSet::GetHealthAttribute();
    ModifierInfo.ModifierOp = EGameplayModOp::Override;
    ModifierInfo.ModifierMagnitude = FGameplayEffectModifierMagnitude(100.f);
    Modifiers.Add(ModifierInfo);
    ModifierInfo = {};
    ModifierInfo.Attribute = UMyAttributeSet::GetDamageAttribute();
    ModifierInfo.ModifierOp = EGameplayModOp::Override;
    ModifierInfo.ModifierMagnitude = FGameplayEffectModifierMagnitude(10.f);
    Modifiers.Add(ModifierInfo);
    ModifierInfo = {};
    ModifierInfo.Attribute = UMyAttributeSet::GetArmorAttribute();
    ModifierInfo.ModifierOp = EGameplayModOp::Override;
    ModifierInfo.ModifierMagnitude = FGameplayEffectModifierMagnitude(0.f);
    Modifiers.Add(ModifierInfo);
    ModifierInfo = {};
    ModifierInfo.Attribute = UMyAttributeSet::GetStrengthAttribute();
    ModifierInfo.ModifierOp = EGameplayModOp::Override;
    ModifierInfo.ModifierMagnitude = FGameplayEffectModifierMagnitude(0.f);
    Modifiers.Add(ModifierInfo);

    ModifierInfo = {};
    ModifierInfo.Attribute = UMyAttributeSet::GetPliabilityAttribute();
    ModifierInfo.ModifierOp = EGameplayModOp::Override;
    ModifierInfo.ModifierMagnitude = FGameplayEffectModifierMagnitude(0.f);
    Modifiers.Add(ModifierInfo);
    ModifierInfo = {};
    ModifierInfo.Attribute = UMyAttributeSet::GetXPAttribute();
    ModifierInfo.ModifierOp = EGameplayModOp::Override;
    ModifierInfo.ModifierMagnitude = FGameplayEffectModifierMagnitude(0.f);
    Modifiers.Add(ModifierInfo);
    ModifierInfo = {};
    ModifierInfo.Attribute = UMyAttributeSet::GetLevelAttribute();
    ModifierInfo.ModifierOp = EGameplayModOp::Override;
    ModifierInfo.ModifierMagnitude = FGameplayEffectModifierMagnitude(1.f);
    Modifiers.Add(ModifierInfo);
    ModifierInfo = {};
    ModifierInfo.Attribute = UMyAttributeSet::GetSPAttribute();
    ModifierInfo.ModifierOp = EGameplayModOp::Override;
    ModifierInfo.ModifierMagnitude = FGameplayEffectModifierMagnitude(0.f);
    Modifiers.Add(ModifierInfo);
    ModifierInfo = {};
    ModifierInfo.Attribute = UMyAttributeSet::GetMoneyAttribute();
    ModifierInfo.ModifierOp = EGameplayModOp::Override;
    ModifierInfo.ModifierMagnitude = FGameplayEffectModifierMagnitude(0.f);
    Modifiers.Add(ModifierInfo);
}
