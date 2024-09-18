// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Turret.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATurret : public ABasePawn
{
	GENERATED_BODY()
public:
	virtual void Tick(float DeltaTime) override;
protected:
	virtual void BeginPlay() override;

private:
	class ATank* Tank;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Combat Components", meta = (AllowPrivateAccess = "true"))
	float SightDist;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Combat Components", meta = (AllowPrivateAccess = "true"))
	float FireRate;

	FTimerHandle FireTimer;
	void CheckFireCondition();
	bool InRange();
};
