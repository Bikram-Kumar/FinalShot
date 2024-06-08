// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"


#include "Player/PlayerCharacter.h"
#include "DataAssets/GunDataAsset.h"


#include "GameManager.generated.h"

USTRUCT()
struct FReferences {
	GENERATED_BODY()

	UPROPERTY()
	UWorld* World;

	UPROPERTY(EditAnywhere)
	APlayerCharacter* Player;

	UPROPERTY(EditAnywhere)
	UGunDataAsset* GunDataAsset;
};




UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FINALSHOT_API UGameManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGameManager();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere)
	FReferences References;

};
