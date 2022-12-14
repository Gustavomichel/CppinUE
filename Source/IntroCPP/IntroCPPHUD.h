// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "IntroCPPHUD.generated.h"

UCLASS()
class AIntroCPPHUD : public AHUD
{
	GENERATED_BODY()

public:
	AIntroCPPHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

