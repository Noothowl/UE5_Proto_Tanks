// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "GameFramework/DamageType.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABaseProjectile::ABaseProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SM_Base = CreateDefaultSubobject<UStaticMeshComponent>("Base Mesh");
	RootComponent = SM_Base;

	ProjectileLogic = CreateDefaultSubobject<UProjectileMovementComponent>("Projectile Logic");
	


}

// Called when the game starts or when spawned
void ABaseProjectile::BeginPlay()
{
	Super::BeginPlay();
	SM_Base->OnComponentHit.AddDynamic(this, &ABaseProjectile::OnHit);
	
}

// Called every frame
void ABaseProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) {
	
	
	auto MyOwner = GetOwner();
	if (MyOwner == nullptr) return;
	auto MyOwnerInstigator = MyOwner->GetInstigatorController();
	auto DmgType = UDamageType::StaticClass();

	if (OtherActor && OtherActor != this && OtherActor != MyOwner)
	{
		UGameplayStatics::ApplyDamage(
			OtherActor,				// Actor that will be damaged.
			BaseDamage,					// Damage amount.
			MyOwnerInstigator,	// Which player instigated it.
			this,					// What actor caused the damage.
			DmgType
		);
		Destroy();
	}

}


