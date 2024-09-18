// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"







ATank::ATank() {
	SA_ForCamera=CreateDefaultSubobject<USpringArmComponent>("Spring Arm");
	SA_ForCamera->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(SA_ForCamera);

}

void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(("MoveForward"), this, &ATank::Move); 
	
}

void ATank::Move(float value){

	UE_LOG(LogTemp, Warning, TEXT("Value: %f"),value);

}
