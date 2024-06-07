// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerControlsManager.h"
#include "DrawDebugHelpers.h"

// Sets default values for this component's properties
UPlayerControlsManager::UPlayerControlsManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPlayerControlsManager::BeginPlay()
{
	Super::BeginPlay();

	Player = Cast<ACharacter>(GetOwner());
	
}


// Called every frame
void UPlayerControlsManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}




void UPlayerControlsManager::MoveForward (float Value) {

	FVector Direction = FRotationMatrix(Player->Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	Player->AddMovementInput(Direction, Value);

}



void UPlayerControlsManager::MoveRight (float Value) {

	FVector Direction = FRotationMatrix(Player->Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	Player->AddMovementInput(Direction, Value);


}




void UPlayerControlsManager::StartJump () {

	Player->bPressedJump = true;
	
}


void UPlayerControlsManager::StopJump () {

	Player->bPressedJump = false;
	
}



void UPlayerControlsManager::Shoot () {

	FHitResult Hit;
	FVector TraceStart = Player->GetActorLocation();
	FVector TraceEnd = TraceStart + (Player->GetActorForwardVector() * 1000.0f);

	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(Player);

	GetWorld()->LineTraceSingleByChannel(Hit, TraceStart, TraceEnd, ECC_Pawn, QueryParams);

	DrawDebugLine(Player->GetWorld(), TraceStart, TraceEnd, FColor::Blue, false, 5.0f, 0, 10.0f);

	if (Hit.bBlockingHit && IsValid(Hit.GetActor())) {
		UE_LOG(LogTemp, Warning, TEXT("Hit"));
	}
}