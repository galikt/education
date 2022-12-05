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
	for (int i = 0; i < 4; ++i)
	{
		FTransform tran(FRotator::ZeroRotator, FVector(0.0f, 120 * i, 100.0f));
		world->SpawnActor<AMyActor>(MyClass, tran);
	}
}

// Called every frame
void AHub::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

