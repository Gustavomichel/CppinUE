// Copyright Epic Games, Inc. All Rights Reserved.

#include "IntroCPPGameMode.h"
#include "IntroCPPHUD.h"
#include "IntroCPPCharacter.h"
#include "UObject/ConstructorHelpers.h"

AIntroCPPGameMode::AIntroCPPGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AIntroCPPHUD::StaticClass();
}
