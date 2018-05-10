// Fill out your copyright notice in the Description page of Project Settings.

#include "ShapeShifterGameMode.h"
#include "UObject/ConstructorHelpers.h"
#include "../Player/MainCharacter.h"

AShapeShifterGameMode::AShapeShifterGameMode()
{
	//Set the default pawn that spawns to be the character blueprint
	static ConstructorHelpers::FClassFinder<AMainCharacter> MainCharacterBP(TEXT("/Game/Blueprints/Player/BP_MainCharacter"));
	if (MainCharacterBP.Class != nullptr)
		DefaultPawnClass = MainCharacterBP.Class;
}

