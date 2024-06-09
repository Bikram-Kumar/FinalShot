// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyManager.h"

// Sets default values for this component's properties
UEnemyManager::UEnemyManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UEnemyManager::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UEnemyManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


void UEnemyManager::EndPlay(const EEndPlayReason::Type EndPlayReason) {

	if (EndPlayReason == EEndPlayReason::Destroyed) {

		UE_LOG(LogTemp, Warning, TEXT("I am getting destroyed... AAAH"));

	}

	Super::EndPlay(EndPlayReason);

}



int UEnemyManager::GetHealth() {
	return Health;
}


void UEnemyManager::ApplyDamage(int Amount) {
	Health -= Amount;

	if (Health <= 0) {
		GetOwner()->Destroy();
	}

}
