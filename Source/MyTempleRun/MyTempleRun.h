// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#define ENUM_TO_INT32(Value) static_cast<int32>(Value) //�������� int32�� ��ȯ
#define ENUM_TO_FSTRING(Enum, Value) FindObject<UEnum>(ANY_PACKAGE, TEXT(Enum), true)->GetDisplayNameTextByIndex((int32)Value).ToString()
//�������� ���÷��� ������ �����ͼ� FString���� ��ȯ

UENUM(BlueprintType)
enum class EItemType : uint8
{
	Bullet,
	Coin,
	MAX
};

UENUM(BlueprintType)
enum class EWeaponType : uint8
{
	Rifle,
	Wire,
	MAX
}; 

UENUM(BlueprintType)
enum class ECameraSetting : uint8
{
	Unequip,
	RifleEquip,
	RifleAim,
	MAX
};

UENUM(BlueprintType)
enum class AbilityID : uint8
{
	None UMETA(DisplayName = "None"),
	Confirm UMETA(DisplayName = "Confirm"),
	Cancel UMETA(DisplayName = "Cancel")
};