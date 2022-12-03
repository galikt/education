// Fill out your copyright notice in the Description page of Project Settings.


#include "Hub.h"
#include "Engine/World.h"

// Sets default values
AHub::AHub()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHub::BeginPlay()
{
	Super::BeginPlay();

	UWorld* world = GetWorld();
	for (int i = 0; i < 10; ++i)
	{
		world->SpawnActor(MyMyActor, FVector(0.0f, 0.0f, i * 1100), FRotator::ZeroRotator);
	}
}

// Called every frame
void AHub::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

