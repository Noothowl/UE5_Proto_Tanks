// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawn.h"
#include "Components/CapsuleComponent.h"
#include "BaseProjectile.h"

// Sets default values
ABasePawn::ABasePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//Components
		//Capsule
	RootCapsule = CreateDefaultSubobject <UCapsuleComponent> ("Root Capsule");
	RootComponent = RootCapsule;
		//Mesh
	SM_Base = CreateDefaultSubobject <UStaticMeshComponent>("Base Mesh");
	SM_Base->SetupAttachment(RootCapsule);
	
	SM_Turret = CreateDefaultSubobject <UStaticMeshComponent>("Turret Mesh");
	SM_Turret->SetupAttachment(SM_Base);
		//Spawn Point
	SC_SpawnProjectile = CreateDefaultSubobject<USceneComponent>("Projectile Spawner");
	SC_SpawnProjectile->SetupAttachment(SM_Turret);
	

}

void ABasePawn::HandleDestruction() {
	//vfx

	//
	
}

// Called when the game starts or when spawned
void ABasePawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABasePawn::Fire()
{
	FVector MySpawnerLoc = SC_SpawnProjectile->GetComponentLocation();
	FRotator MySpawnerRot = SC_SpawnProjectile->GetComponentRotation();
	
	auto Projectile = GetWorld()->SpawnActor<ABaseProjectile>(BaseProjectileClass, MySpawnerLoc, MySpawnerRot);
	Projectile->SetOwner(this);

}

// Called to bind functionality to input
void ABasePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
void ABasePawn::RotateTurret(FVector Target) {
	FVector ToTarget = Target - SM_Turret->GetComponentLocation();
	FRotator RotToTarget = FRotator(0.f, ToTarget.Rotation().Yaw, 0.f);
	
	SM_Turret->SetWorldRotation(
		FMath::RInterpTo(SM_Turret->GetComponentRotation(),
			RotToTarget,
			GetWorld()->GetDeltaSeconds(),
			5));
}

