// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MyHUD.generated.h"

/**
 * 
 */
UCLASS()
class MYTEMPLERUN_API AMyHUD : public AHUD
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My|User Widget")
	TArray<TSubclassOf<UUserWidget>> UserWidgetArray;

	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My|User Widget")
	class UHealthUserWidget* HealthWidget;*/

	void Init(APlayerController* PlayerController);
};
