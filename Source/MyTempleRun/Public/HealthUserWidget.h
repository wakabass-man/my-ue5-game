// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HealthUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class MYTEMPLERUN_API UHealthUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	float HealthPercent;

public:
	void BindToAttribute(APlayerController* PlayerController);
};
