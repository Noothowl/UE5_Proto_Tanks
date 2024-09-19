// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"


ATank::ATank() {
	SA_ForCamera=CreateDefaultSubobject<USpringArmComponent>("Spring Arm");
	SA_ForCamera->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(SA_ForCamera);


}
void ATank::HandleDestruction() {
	Super::HandleDestruction();

	SetActorHiddenInGame(true);
	SetActorTickEnabled(false);
}

void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(("MoveForward"), this, &ATank::Move); 
	PlayerInputComponent->BindAxis(("Turn"), this, &ATank::Turn);
	PlayerInputComponent->BindAction("Fire",IE_Pressed,this,&ATank::Fire);
}

void ATank::Move(float Value)
{	
	FVector DeltaLoc(0.f, 0.f, 0.f);

	DeltaLoc.X = Value * MSpeed * UGameplayStatics::GetWorldDeltaSeconds(this);
	AddActorLocalOffset(DeltaLoc, true);
}

void ATank::Turn(float Value) {
	FRotator DeltaRot(0.f, 0.f, 0.f);
	DeltaRot.Yaw = Value * TRate * UGameplayStatics::GetWorldDeltaSeconds(this);
	AddActorLocalRotation(DeltaRot, true);
}

void ATank::Fire(){
	Super::Fire();


}

void ATank::BeginPlay()
{
	Super::BeginPlay();

	TankPlayerControllerPtr = Cast<APlayerController>(GetController());
	
}

void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (TankPlayerControllerPtr) {
		FHitResult Res;
		TankPlayerControllerPtr->GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, Res);
		DrawDebugSphere(GetWorld(),
			Res.ImpactPoint,
			25.f,
			12.f,
			FColor::Red,
			false,
			-1.f);

		RotateTurret(Res.ImpactPoint);
	}
}