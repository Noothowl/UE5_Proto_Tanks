// Fill out your copyright notice in the Description page of Project Settings.


#include "Turret.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"


void ATurret::BeginPlay() {
	Super::BeginPlay();

	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
	GetWorldTimerManager().SetTimer(FireTimer,this, &ATurret::CheckFireCondition, FireRate, true);
}

void ATurret::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

		if (InRange())
		{
			RotateTurret(Tank->GetActorLocation());
		}
	
 }

void ATurret::CheckFireCondition() {
	if (InRange())
	{
		Fire();
	}
}

bool ATurret::InRange() {


	float Distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());
	
	if (Tank)
	{
		if (Distance <= SightDist)
		{
			return true;
		}
		else return false;
	}
	else return false;
}

void ATurret::HandleDestruction() {
	Super::HandleDestruction();
	Destroy();
}

