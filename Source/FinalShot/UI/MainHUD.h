// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"

#include "Engine/Canvas.h"

#include "MainHUD.generated.h"

/**
 * 
 */
UCLASS()
class FINALSHOT_API AMainHUD : public AHUD
{
	GENERATED_BODY()


	protected:

		UPROPERTY(EditDefaultsOnly)
		UTexture2D* CrossHairTexture;
	

	public:

		virtual void DrawHUD() override;
};
