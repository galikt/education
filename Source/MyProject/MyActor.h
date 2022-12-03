// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "MyActor.generated.h"


UENUM(BlueprintType)
enum class Change : uint8
{
	one,
	two
};

USTRUCT(BlueprintType)
struct FMyStruct
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere)
	uint32 Value {44};

	UPROPERTY(EditAnywhere)
	FString String = "44";
};


UCLASS()
class MYPROJECT_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AMyActor();

	UPROPERTY(EditAnywhere)
	int32 Value;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
	FMyStruct MyStruct;

	UPROPERTY(EditAnywhere)
	Change Test;

	UPROPERTY(EditAnywhere)
	FLinearColor Color = FLinearColor::Black;

	FTimerHandle Timer;

	void OnTimer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
