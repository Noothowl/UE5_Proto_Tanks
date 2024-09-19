// Fill out your copyright notice in the Description page of Project Settings.


#include "ProtoTanksGMode.h"
#include "Kismet/GameplayStatics.h"
#include "Tank.h"
#include "Turret.h"


void AProtoTanksGMode::BeginPlay(){
	Super::BeginPlay();

	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this,0));
}

void AProtoTanksGMode::ActorDied(AActor* DeadActor) {
	if (DeadActor==Tank) {
		Tank->HandleDestruction();
		if (Tank->GetTankPlayerControllerPtr())
		{
			Tank->DisableInput(Tank->GetTankPlayerControllerPtr());
		}
	}
	else if (ATurret* DestroyedTurret = Cast<ATurret>(DeadActor)) {
		DestroyedTurret->HandleDestruction();
	}
}