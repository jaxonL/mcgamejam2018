// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "SurviveGameMode.h"
#include "SurviveCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASurviveGameMode::ASurviveGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
