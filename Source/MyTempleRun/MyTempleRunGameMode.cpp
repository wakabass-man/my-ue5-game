// Copyright Epic Games, Inc. All Rights Reserved.

#include "MyTempleRunGameMode.h"
#include "MyTempleRunCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMyTempleRunGameMode::AMyTempleRunGameMode()
{
	// set default pawn class to our Blueprinted character
	/*static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));*/
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Mine/TestCharacter.TestCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
