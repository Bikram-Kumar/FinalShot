// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EnemyManager.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FINALSHOT_API UEnemyManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UEnemyManager();


protected:
	
	UPROPERTY()
	int Health = 100;

	virtual void BeginPlay() override;


public:	

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;


	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION()
	int GetHealth();

	UFUNCTION()
	void ApplyDamage(int Amount);



};
