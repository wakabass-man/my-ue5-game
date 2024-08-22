// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseItemStruct.generated.h"

/**
 * 
 */

class MYTEMPLERUN_API BaseItemStruct
{
public:
	BaseItemStruct();
	~BaseItemStruct();
};

USTRUCT(Atomic, BlueprintType)
struct FBaseItemStruct
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Name)
	FName Name;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Amount)
	int32 Amount;
};