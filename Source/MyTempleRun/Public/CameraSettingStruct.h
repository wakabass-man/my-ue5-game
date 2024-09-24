// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CameraSettingStruct.generated.h"

/**
 * 
 */

class MYTEMPLERUN_API CameraSettingStruct
{
public:
	CameraSettingStruct();
	~CameraSettingStruct();
};

USTRUCT(Atomic, BlueprintType)
struct FCameraSettingStruct
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = CameraSetting)
	float TargetArmLength;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = CameraSetting)
	FVector SocketOffset;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = CameraSetting)
	FVector CameraBoomRelativeLocation;
};