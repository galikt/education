// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");
	SetRootComponent(Mesh);
}

void AMyActor::OnTimer()
{
	UMaterialInstanceDynamic* mat = Mesh->CreateAndSetMaterialInstanceDynamic(0);
	if (mat)
	{
		FLinearColor color = FLinearColor::MakeRandomColor();
		mat->SetVectorParameterValue("Param", color);
		OnColorChanged.Broadcast(color, GetName());
	}

	static int count = 5;
	if (count == 0)
	{
		GetWorldTimerManager().ClearTimer(Timer);
		OnTimerFinished.Broadcast(this);
	}
	--count;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	UMaterialInstanceDynamic* mat = Mesh->CreateAndSetMaterialInstanceDynamic(0);
	if (mat)
	{
		mat->SetVectorParameterValue("Param", Color);
	}

	GetWorldTimerManager().SetTimer(Timer, this, &AMyActor::OnTimer, 1.0f, true);
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float t = GetWorld()->GetTimeSeconds();

	FVector p = GetActorLocation();
	p.Z = p.Z + FMath::Sin(t * 4) * 4;
	SetActorLocation(p);
}

