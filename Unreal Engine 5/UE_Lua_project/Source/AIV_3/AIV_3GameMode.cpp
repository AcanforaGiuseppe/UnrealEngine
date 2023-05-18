// Copyright Epic Games, Inc. All Rights Reserved.

#include "AIV_3GameMode.h"
#include "AIV_3Character.h"
#include "UObject/ConstructorHelpers.h"

AAIV_3GameMode::AAIV_3GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
