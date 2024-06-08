// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

#include "PlayerControlsManager.h"


// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	MainCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("MainCamera"));

	check(MainCameraComponent != nullptr);
	MainCameraComponent->SetupAttachment(CastChecked<USceneComponent, UCapsuleComponent>(GetCapsuleComponent()));

	MainCameraComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f + BaseEyeHeight));

	MainCameraComponent->bUsePawnControlRotation = true;





	HandMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("HandMesh"));
	check(HandMesh != nullptr);

	HandMesh->SetOnlyOwnerSee(true);
	HandMesh->SetupAttachment(MainCameraComponent);

	HandMesh->bCastDynamicShadow = false;
	HandMesh->CastShadow = false;

	GetMesh()->SetOwnerNoSee(true);



}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	check(GEngine != nullptr);

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Character is live"));
	
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UPlayerControlsManager* man = FindComponentByClass<UPlayerControlsManager>();


	PlayerInputComponent->BindAxis("MoveForward", man, &UPlayerControlsManager::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", man, &UPlayerControlsManager::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &APlayerCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APlayerCharacter::AddControllerPitchInput);


	PlayerInputComponent->BindAction("Jump", IE_Pressed, man, &UPlayerControlsManager::StartJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, man, &UPlayerControlsManager::StopJump);

	PlayerInputComponent->BindAction("Shoot", IE_Pressed, man, &UPlayerControlsManager::Shoot);


}





void APlayerCharacter::Shoot () {

	if (GrenadeClass) {

		FVector CameraLocation;
		FRotator CameraRotation;
		GetActorEyesViewPoint(CameraLocation, CameraRotation);

		MuzzleOffset.Set(100.0f, 0.0f, 0.0f);

		FVector MuzzleLocation = CameraLocation + FTransform(CameraRotation).TransformVector(MuzzleOffset);

		FRotator MuzzleRotation = CameraRotation;
		MuzzleRotation.Pitch += 10.0f;

		UWorld* World = GetWorld();

		if (World) {

			FActorSpawnParameters SpawnParams;

			SpawnParams.Owner = this;
			SpawnParams.Instigator = GetInstigator();

			AGrenade* Grenade = World->SpawnActor<AGrenade>(GrenadeClass, MuzzleLocation, MuzzleRotation, SpawnParams);
			if (Grenade) {
				FVector ShootDirection = MuzzleRotation.Vector();
        		Grenade->ShootInDirection(ShootDirection);
			}
   

		}


	}
	
}
