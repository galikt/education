// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	void BeginPlay() override;

protected:
	void SetupInputComponent() override;
	void ChangePawn();

	UPROPERTY()
	TArray<AActor*> Pawns;

	uint32 Index = 0;
};
