// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ProtoTanksGMode.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API AProtoTanksGMode : public AGameModeBase
{
	GENERATED_BODY()
public:
	void ActorDied(AActor* DeadActor);
protected:
	virtual void BeginPlay() override;
	UFUNCTION(BlueprintImplementableEvent)
	void StartGame();
	UFUNCTION(BlueprintImplementableEvent)
	void EndGame(bool WonGame);
private:
	class ATank* Tank;
	class AProtoTanksController* ProtoTanksController;
	float StartDelay = 3.f;

	int32 TargetEnemies = 0;
	int32 GetEnemiesCount();

	void HandleGameStart();
};
