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
	
}


// Called every frame
void UPlayerControlsManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}




void UPlayerControlsManager::MoveForward (float Value) {

	FVector Direction = FRotationMatrix(GM->Player->Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	GM->Player->AddMovementInput(Direction, Value);

}



void UPlayerControlsManager::MoveRight (float Value) {

	FVector Direction = FRotationMatrix(GM->Player->Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	GM->Player->AddMovementInput(Direction, Value);


}




void UPlayerControlsManager::StartJump () {

	GM->Player->bPressedJump = true;
	
}


void UPlayerControlsManager::StopJump () {

	GM->Player->bPressedJump = false;
	
}



void UPlayerControlsManager::Shoot () {

	FHitResult Hit;
	FVector Forward = GM->Player->GetControlRotation().Vector();
	
	FVector TraceStart = GM->Player->GetActorLocation() + (FVector::UpVector * HandsHeight) + (Forward * GunMuzzleDistance);
	FVector TraceEnd = TraceStart + (Forward * BulletRange);

	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(GM->Player);

	GetWorld()->LineTraceSingleByChannel(Hit, TraceStart, TraceEnd, ECC_Pawn, QueryParams);

	DrawDebugLine(GM->World, TraceStart, TraceEnd, FColor::Blue, false, 5.0f, 0, 10.0f);

	AActor* Actor = Hit.GetActor();

	if (Hit.bBlockingHit && IsValid(Actor)) {
		if (Actor->ActorHasTag(FName(TEXT("Enemy")))) {

			FName EquippedGun = GM->Player->FindComponentByClass<UPlayerManager>()->EquippedGun;

			int DamageAmount = GM->GunDataAsset->Guns[EquippedGun].Damage;
			
			Actor->FindComponentByClass<UEnemyManager>()->ApplyDamage(DamageAmount);

			UE_LOG(LogTemp, Warning, TEXT("Enemy Health: %d"), Actor->FindComponentByClass<UEnemyManager>()->GetHealth());
		}
	}
}