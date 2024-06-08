// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerManager.h"

// Sets default values for this component's properties
UPlayerManager::UPlayerManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPlayerManager::BeginPlay()
{
	Super::BeginPlay();

	GameManager = FindObject<AActor>(GetOwner()->GetWorld()->GetCurrentLevel(), TEXT("GameManager"))->FindComponentByClass<UGameManager>();

	UE_LOG(LogTemp, Warning, TEXT("Damage of AR4: %d"), GameManager->References.GunDataAsset->Guns[FName(TEXT("AR4"))].Damage);
	
}


// Called every frame
void UPlayerManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

