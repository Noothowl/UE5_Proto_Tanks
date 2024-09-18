// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()
private:
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Camera Components", meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* SA_ForCamera;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Camera Components", meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* Camera;

	void Move(float value);

public:
	ATank();
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
};
