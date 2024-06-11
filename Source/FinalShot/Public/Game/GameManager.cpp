// Fill out your copyright notice in the Description page of Project Settings.


#include "GameManager.h"
#include "Player/PlayerManager.h"


AGameManager::AGameManager()
{

	PrimaryActorTick.bCanEverTick = true;

}


void AGameManager::BeginPlay()
{
	Super::BeginPlay();

	World = GetWorld();
	PlayerCamera = Player->FindComponentByClass<UCameraComponent>();
	PlayerManager = Player->FindComponentByClass<UPlayerManager>();
	
}

void AGameManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// ...
}

