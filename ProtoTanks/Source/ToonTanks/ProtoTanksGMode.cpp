// Fill out your copyright notice in the Description page of Project Settings.


#include "ProtoTanksGMode.h"
#include "Kismet/GameplayStatics.h"
#include "Tank.h"
#include "Turret.h"
#include "ProtoTanksController.h"


void AProtoTanksGMode::BeginPlay(){
	Super::BeginPlay();

	HandleGameStart();

}

void AProtoTanksGMode::ActorDied(AActor* DeadActor) {
	if (DeadActor==Tank) {
		Tank->HandleDestruction();
		if (Tank->GetTankPlayerControllerPtr())
		{
			ProtoTanksController->SetPlayerEnabledState(false);
		}
	}
	else if (ATurret* DestroyedTurret = Cast<ATurret>(DeadActor)) {
		DestroyedTurret->HandleDestruction();
	}
}

void AProtoTanksGMode::HandleGameStart(){

	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
	ProtoTanksController = Cast<AProtoTanksController>(UGameplayStatics::GetPlayerController(this, 0));

	StartGame();

	if (ProtoTanksController) {
		ProtoTanksController->SetPlayerEnabledState(false);

		FTimerHandle PlayerEnabledTimerHandle;

		FTimerDelegate PlayerEnabledDelegate = FTimerDelegate::CreateUObject(ProtoTanksController, &AProtoTanksController::SetPlayerEnabledState, true);

		GetWorldTimerManager().SetTimer(PlayerEnabledTimerHandle, PlayerEnabledDelegate, StartDelay, false);
	}
}

