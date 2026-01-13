// Fill out your copyright notice in the Description page of Project Settings.


#include "ChallengeObstacleSpawner.h"
#include "ChallengeObstacle.h"

AChallengeObstacleSpawner::AChallengeObstacleSpawner()
{
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AChallengeObstacleSpawner::BeginPlay()
{
	Super::BeginPlay();

	for (int i = 0; i < NumberOfActorToSpawn; i++)
	{
		SpawnObstacle();
	}
}

FRotator AChallengeObstacleSpawner::GetRandomRotation()
{
	int X = FMath::RandRange(0, 360);
	int Y = FMath::RandRange(0, 360);
	int Z = FMath::RandRange(0, 360);

	return FRotator(X, Y, Z);
}

FVector AChallengeObstacleSpawner::GetRandomLocation()
{
	int X = FMath::RandRange(-1000, 1000);
	int Y = FMath::RandRange(-1000, 1000);
	int Z = FMath::RandRange(10, 1000);

	return FVector(X, Y, Z);
}

void AChallengeObstacleSpawner::SpawnObstacle()
{
	FRotator RandomRotation = GetRandomRotation();
	FVector RandomLocation = GetRandomLocation();

	AChallengeObstacle* NewObstacle = GetWorld()->SpawnActor<AChallengeObstacle>(RandomLocation, RandomRotation);

	if (NewObstacle)
	{
		int MeshIndex = FMath::RandRange(0, MeshList.Num() - 1);
		int MaterialIndex = FMath::RandRange(0, MaterialList.Num() - 1);

		NewObstacle->SetObstacleVisual(MeshList[MeshIndex], MaterialList[MaterialIndex]);
	}
}
