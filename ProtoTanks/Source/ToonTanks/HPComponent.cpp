// Fill out your copyright notice in the Description page of Project Settings.


#include "HPComponent.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "ProtoTanksGMode.h"


// Sets default values for this component's properties
UHPComponent::UHPComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHPComponent::BeginPlay()
{
	Super::BeginPlay();

	HP = MaxHP;
	//Binding delegate
	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHPComponent::DamageTaken);
	ProtoTanksGMode = Cast<AProtoTanksGMode>(UGameplayStatics::GetGameMode(this));
	
}


// Called every frame
void UHPComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHPComponent::DamageTaken(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* Instigator, AActor* DamageCauser) {
	if (Damage <= 0.f) return;
	HP -= Damage;

	if (HP <= 0.f && ProtoTanksGMode)
	{
		ProtoTanksGMode->ActorDied(DamagedActor);
	}
}
