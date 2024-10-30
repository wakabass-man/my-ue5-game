// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#define ENUM_TO_INT32(Value) static_cast<int32>(Value) //열거형을 int32로 변환
#define ENUM_TO_FSTRING(Enum, Value) FindObject<UEnum>(ANY_PACKAGE, TEXT(Enum), true)->GetDisplayNameTextByIndex((int32)Value).ToString()
//열거형의 디스플레이 네임을 가져와서 FString으로 변환

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