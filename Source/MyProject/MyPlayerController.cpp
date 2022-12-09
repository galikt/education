// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "MyPawn.h"
#include "Kismet/GameplayStatics.h"

void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("ChangePawn", IE_Pressed, this, &AMyPlayerController::ChangePawn);
}

void AMyPlayerController::ChangePawn()
{
	if (Pawns.Num() > 1)
	{
		AMyPawn* pawn = Cast<AMyPawn>(Pawns[Index]);
		if (pawn)
		{
			Possess(pawn);
		}
		Index = (Index + 1) % Pawns.Num();
	}
}

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AMyPawn::StaticClass(), Pawns);
}
