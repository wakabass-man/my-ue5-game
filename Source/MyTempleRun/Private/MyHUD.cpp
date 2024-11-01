// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHUD.h"
#include "HealthUserWidget.h"
#include "MyPlayerController.h"

void AMyHUD::Init(APlayerController* PlayerController)
{
	ensure(UserWidgetArray.Num() > 0);
	/*UHealthUserWidget* Widget = nullptr;*/
	for (const auto& e : UserWidgetArray)
	{
		auto Widget = CreateWidget<UHealthUserWidget>(PlayerController, e);
		Widget->BindToAttribute(PlayerController);
		Widget->AddToViewport();
	}
}