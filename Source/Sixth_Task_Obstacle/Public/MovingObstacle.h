// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingObstacle.generated.h"

UCLASS()
class SIXTH_TASK_OBSTACLE_API AMovingObstacle : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMovingObstacle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Moving Obstacle|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Moving Obstacle|Components")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Moving Obstacle|Properties")
	float MoveSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Moving Obstacle|Properties")
	float MaxRange;

	FVector StartLocation;
	FVector EndLocation;
	bool bShouldReturn = false;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
