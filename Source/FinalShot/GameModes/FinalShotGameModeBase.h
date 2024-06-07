// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "../DataAssets/GunDataAsset.h"

#include "FinalShotGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class FINALSHOT_API AFinalShotGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	protected:
		virtual void StartPlay() override;

	public:
		UPROPERTY(EditAnywhere)
		UGunDataAsset* GunDataAsset;
	
};
