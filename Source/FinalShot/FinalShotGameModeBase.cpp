// Copyright Epic Games, Inc. All Rights Reserved.


#include "FinalShotGameModeBase.h"


void AFinalShotGameModeBase::StartPlay()
{
Super::StartPlay();

check(GEngine != nullptr);

  GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Hello!"));

}