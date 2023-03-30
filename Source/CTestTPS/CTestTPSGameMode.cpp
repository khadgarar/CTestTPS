// Copyright Epic Games, Inc. All Rights Reserved.

#include "CTestTPSGameMode.h"
#include "CTestTPSCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACTestTPSGameMode::ACTestTPSGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
