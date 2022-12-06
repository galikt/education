// Fill out your copyright notice in the Description page of Project Settings.


#include "Hub.h"
#include "Engine/World.h"

// Sets default values
AHub::AHub()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AHub::OnColorChanched(const FLinearColor& color, const FString& name)
{
	UE_LOG(LogTemp, Warning, TEXT("COLOR"));
}

void AHub::OnTimerFinished(AActor* actor)
{
	UE_LOG(LogTemp, Warning, TEXT("FINISHED"));

	AMyActor* act = Cast<AMyActor>(actor);
	if (act)
	{
		UE_LOG(LogTemp, Error, TEXT("NO ERROR"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("ERROR"));
	}

	act->SetLifeSpan(2.0f);
}

// Called when the game starts or when spawned
void AHub::BeginPlay()
{
	Super::BeginPlay();

	UWorld* world = GetWorld();
	for (int i = 0; i < 4; ++i)
	{
		FTransform tran(FRotator::ZeroRotator, FVector(300.0f, 120 * i, 100.0f));
		AMyActor* actor = world->SpawnActor<AMyActor>(MyClass, tran);

		actor->OnColorChanged.AddDynamic(this, &AHub::OnColorChanched);
		actor->OnTimerFinished.AddUObject(this, &AHub::OnTimerFinished);
	}
}

// Called every frame
void AHub::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

