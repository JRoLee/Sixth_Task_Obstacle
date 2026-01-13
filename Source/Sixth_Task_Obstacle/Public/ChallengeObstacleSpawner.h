// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ChallengeObstacleSpawner.generated.h"

UCLASS()
class SIXTH_TASK_OBSTACLE_API AChallengeObstacleSpawner : public AActor
{
	GENERATED_BODY()

public:
	AChallengeObstacleSpawner();

protected:
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Challenge Obstacle Spawner|Properties");
	int NumberOfActorToSpawn;

	UPROPERTY(EditAnywhere, Category="Challenge Obstacle Spawner|Data")
	TArray<UStaticMesh*> MeshList;

	UPROPERTY(EditAnywhere, Category="Challenge Obstacle Spawner|Data")
	TArray<UMaterialInterface*> MaterialList;

	FRotator GetRandomRotation();
	FVector GetRandomLocation();

	void SpawnObstacle();
};
