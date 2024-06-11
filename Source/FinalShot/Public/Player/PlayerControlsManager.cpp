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

void UPlayerControlsManager::ShootStart () {

	Shoot();

	float Rate = 60.f / GM->PlayerManager->GetEquippedGunData().FireRate; // per minute to second difference

	// Rate is not rate, but timediff between two consecutive calls
	GM->World->GetTimerManager().SetTimer(ShootingTimerHandle, this, &UPlayerControlsManager::Shoot, Rate, true, 0.f);

}


void UPlayerControlsManager::ShootEnd () {

	GM->World->GetTimerManager().ClearTimer(ShootingTimerHandle);

} 


void UPlayerControlsManager::Shoot () {

	FHitResult Hit;
	FVector Forward = GM->PlayerCamera->GetComponentTransform().GetRotation().GetAxisX();
	
	FVector TraceStart = GM->PlayerCamera->GetComponentLocation() + (GunMuzzleDistance * Forward);
	FVector TraceEnd = TraceStart + (Forward * BulletRange);

	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(GM->Player);

	GetWorld()->LineTraceSingleByChannel(Hit, TraceStart, TraceEnd, ECC_Pawn, QueryParams);

	DrawDebugLine(GM->World, TraceStart, TraceEnd, FColor::Yellow, false, 5.0f, 0, 5.0f);

	AActor* Actor = Hit.GetActor();

	if (Hit.bBlockingHit && IsValid(Actor)) {
		if (Actor->ActorHasTag(FName(TEXT("Enemy")))) {

			int DamageAmount = GM->PlayerManager->GetEquippedGunData().Damage;
			
			Actor->FindComponentByClass<UEnemyManager>()->ApplyDamage(DamageAmount);

			UE_LOG(LogTemp, Warning, TEXT("Enemy Health: %d"), Actor->FindComponentByClass<UEnemyManager>()->GetHealth());
		}
	}

	PlayBulletSound();

	float VRecoil = GM->PlayerManager->GetEquippedGunData().VerticalRecoil;
	float HRecoil = GM->PlayerManager->GetEquippedGunData().HorizontalRecoil;
	
	GM->Player->AddControllerYawInput(FMath::RandRange(-HRecoil, HRecoil));
	GM->Player->AddControllerPitchInput(-VRecoil);


}



void UPlayerControlsManager::PlayBulletSound() {
	
	UGameplayStatics::PlaySound2D(GM->World, GM->PlayerManager->GetEquippedGunData().BulletSound);

}


