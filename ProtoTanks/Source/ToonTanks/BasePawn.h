// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void RotateTurret(FVector Target);
	void Fire();
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void HandleDestruction();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
private:
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Pawn Components", meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent* RootCapsule;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Pawn Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* SM_Base;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Pawn Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* SM_Turret;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Pawn Components",meta=(AllowPrivateAccess = "true"))
	USceneComponent* SC_SpawnProjectile;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Combat Components", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class ABaseProjectile> BaseProjectileClass;

};
