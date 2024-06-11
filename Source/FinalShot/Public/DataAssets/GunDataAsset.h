// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"

#include "GunDataAsset.generated.h"


USTRUCT()
struct FGunData {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere)
    int AmmoCount;

    UPROPERTY(EditAnywhere)
    int Damage;

    // In Degrees
    UPROPERTY(EditAnywhere)
    float HorizontalRecoil;

    // In Degrees
    UPROPERTY(EditAnywhere)
    float VerticalRecoil;

    // Per Minute
    UPROPERTY(EditAnywhere)
    int FireRate; 

    UPROPERTY(EditAnywhere)
    float TriggerReleaseTime; 

    UPROPERTY(EditAnywhere)
    USoundBase* BulletSound; 


};




UCLASS()
class FINALSHOT_API UGunDataAsset : public UDataAsset {

    GENERATED_BODY()
    public:
        UPROPERTY(EditAnywhere)
        TMap<FName, FGunData> Guns;

};