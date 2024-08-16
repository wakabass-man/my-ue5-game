// Fill out your copyright notice in the Description page of Project Settings.

#include "RushProjectile.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
ARushProjectile::ARushProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = SphereCollision;
	SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
	SphereCollision->SetSphereRadius(35.f);
	SphereCollision->SetCollisionProfileName(FName("RushProjectile"));
	SphereCollision->SetSimulatePhysics(true);
	/*SphereCollision->SetNotifyRigidBodyCollision(true);*/
	SphereCollision->SetMassOverrideInKg(FName(NAME_None), 500.f);

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovemnet"));
	ProjectileMovement->InitialSpeed = 1500.f;

	SetLifeSpan(5.f);
}

// Called when the game starts or when spawned
void ARushProjectile::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ARushProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

