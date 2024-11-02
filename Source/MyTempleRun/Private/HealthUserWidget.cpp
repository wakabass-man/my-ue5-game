// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthUserWidget.h"
#include "MyAttributeSet.h"
#include "MyTempleRun/MyTempleRunCharacter.h"
#include "MyPlayerController.h"

void UHealthUserWidget::BindToAttribute(APlayerController* PlayerController)
{
	auto Owner = Cast<AMyTempleRunCharacter>(PlayerController->GetPawn());
	auto ASC = Owner->GetAbilitySystemComponent();
	auto AttributeSet = Owner->GetAttributeSet();

	HealthPercent = AttributeSet->GetHealthAttribute().GetNumericValue(AttributeSet) /
					AttributeSet->GetMaxHealthAttribute().GetNumericValue(AttributeSet);

	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("%f"), HealthPercent));

	auto ValueChangeDelegate = ASC->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetHealthAttribute()).AddLambda(
					[this, AttributeSet](const FOnAttributeChangeData& Data) -> void {
					HealthPercent = Data.NewValue / AttributeSet->GetMaxHealthAttribute().GetNumericValue(AttributeSet);
					});
}
