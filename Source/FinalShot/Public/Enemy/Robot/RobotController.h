// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/CharacterMovementComponent.h"


#include "RobotController.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FINALSHOT_API URobotController : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URobotController();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere)
	float Health = 100.0f;

	UFUNCTION(BlueprintCallable)
	void UpdateWalkSpeed(float NewWalkSpeed);

};
