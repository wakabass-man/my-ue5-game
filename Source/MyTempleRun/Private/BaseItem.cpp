// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseItem.h"
#include "Components/SphereComponent.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "MyTempleRun/MyTempleRunCharacter.h"

// Sets default values
ABaseItem::ABaseItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	RootComponent = SphereCollision;
	SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
	SphereCollision->SetSphereRadius(64.f);
	RotatingComponent = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("RotatingMovement"));
}

// Called when the game starts or when spawned
void ABaseItem::BeginPlay()
{
	Super::BeginPlay();
	
	/*SphereCollision->OnComponentBeginOverlap.AddDynamic(this, &ABaseItem::BeginOverlap);*/
}

// Called every frame
void ABaseItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//void ABaseItem::BeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
//	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
//{
//	if (AMyTempleRunCharacter* Player = Cast<AMyTempleRunCharacter>(OtherActor))
//	{
//		Player->GetInventory().Emplace(this);
//		Player->UpdateInventory()
//		Destroy();
//	}
//}