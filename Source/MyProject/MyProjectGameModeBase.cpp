// Copyright Epic Games, Inc. All Rights Reserved.


#include "MyProjectGameModeBase.h"
#include "MyPawn.h"

AMyProjectGameModeBase::AMyProjectGameModeBase()
{
	DefaultPawnClass = AMyPawn::StaticClass();
}