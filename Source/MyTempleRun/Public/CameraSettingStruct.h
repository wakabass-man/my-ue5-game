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

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = CameraSetting, meta = (AllowPrivateAccess = "true"))
	float TargetArmLength;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = CameraSetting, meta = (AllowPrivateAccess = "true"))
	FVector SocketOffset;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = CameraSetting, meta = (AllowPrivateAccess = "true"))
	FVector CameraBoomRelativeLocation;
};