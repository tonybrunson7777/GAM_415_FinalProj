// Copyright Epic Games, Inc. All Rights Reserved.

#include "GAM_415_FinalProjGameMode.h"
#include "GAM_415_FinalProjCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGAM_415_FinalProjGameMode::AGAM_415_FinalProjGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
