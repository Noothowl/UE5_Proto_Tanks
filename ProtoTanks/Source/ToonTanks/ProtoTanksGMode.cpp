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
			
		} EndGame(false);
	}
	else if (ATurret* DestroyedTurret = Cast<ATurret>(DeadActor)) {
		DestroyedTurret->HandleDestruction();
		--TargetEnemies;
		if (TargetEnemies==0)
		{
			EndGame(true);
		}
	}
}

void AProtoTanksGMode::HandleGameStart(){

	TargetEnemies = GetEnemiesCount();
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

int32 AProtoTanksGMode::GetEnemiesCount() {
	 TArray<AActor*> Enemies;
	 UGameplayStatics::GetAllActorsOfClass(this, ATurret::StaticClass(), Enemies);
	
	return Enemies.Num();
}

