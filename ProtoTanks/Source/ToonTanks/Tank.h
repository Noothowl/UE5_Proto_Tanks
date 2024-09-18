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

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Input Components", meta = (AllowPrivateAccess = "true"))
	float MSpeed;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Input Components", meta = (AllowPrivateAccess = "true"))
	float TRate;


	void Move(float value);
	virtual void Fire();
	void Turn(float value);

	class APlayerController* PlayerControllerRef;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	ATank();
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void Tick(float DeltaTime) override;
	
};
