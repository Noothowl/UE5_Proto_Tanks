// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseProjectile.generated.h"

UCLASS()
class TOONTANKS_API ABaseProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Projectile Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* SM_Base;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Projectile Components", meta = (AllowPrivateAccess = "true"))
	class UProjectileMovementComponent* ProjectileLogic;
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};