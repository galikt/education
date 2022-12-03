// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.h"
#include "Hub.generated.h"

UCLASS()
class MYPROJECT_API AHub : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHub();

	UPROPERTY(EditAnywhere)
	TSubclassOf<AMyActor> MyClass;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
