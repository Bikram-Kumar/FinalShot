// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Player/PlayerCharacter.h"
#include "DataAssets/GunDataAsset.h"


#include "GameManager.generated.h"





UCLASS()
class FINALSHOT_API AGameManager : public AActor
{
	GENERATED_BODY()

public:	

	AGameManager();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
	UWorld* World;

	UPROPERTY(EditAnywhere)
	APlayerCharacter* Player;

	UPROPERTY(EditAnywhere)
	UGunDataAsset* GunDataAsset;
	

};
