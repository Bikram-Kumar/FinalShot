// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Actor.h"

#include "Player/PlayerCharacter.h"
#include "Player/PlayerManager.h"
#include "Enemy/EnemyManager.h"
#include "Game/GameManager.h"

#include "PlayerControlsManager.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FINALSHOT_API UPlayerControlsManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerControlsManager();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere)
	AGameManager* GM;

	UPROPERTY(EditAnywhere)
	float HandsHeight = 100.0f;

	UPROPERTY(EditAnywhere)
	float GunMuzzleDistance = 90.0f; // Distance of muzzle from the body

	UPROPERTY()
	float BulletRange = 3000.0f;




	UFUNCTION()
	void MoveForward(float Value);

	UFUNCTION()
	void MoveRight(float Value);

	UFUNCTION()
	void StartJump();

	UFUNCTION()
	void StopJump();

	UFUNCTION()
	void Shoot();
	







	
		
};
