#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ChallengeObstacle.generated.h"

UCLASS()
class SIXTH_TASK_OBSTACLE_API AChallengeObstacle : public AActor
{
	GENERATED_BODY()

public:
	AChallengeObstacle();

	void SetObstacleVisual(UStaticMesh* InMesh, UMaterialInterface* InMaterial);

protected:
	virtual void BeginPlay() override;
	virtual void OnConstruction(const FTransform& Transform) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Challenge Obstacle|Components")
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Challenge Obstacle|Components")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ExposeOnSpawn = true))
	UStaticMesh* ObstacleMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ExposeOnSpawn = true))
	UMaterialInterface* ObstacleMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Challenge Obstacle|Properties");
	float MoveSpeed = FMath::RandRange(1.0f, 10.0f);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Challenge Obstacle|Properties");
	float MaxRange = FMath::RandRange(500.0f, 2000.0f);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Challenge Obstacle|Properties");
	float RotationSpeed = FMath::RandRange(1.0f, 10.0f);

	void MoveObstacle();
	void DestroyObstacle();
	void RotateObstacle();

	void RandomAction();
	FRotator GetRandomRotationAxis();
	FVector GetRandomMoveDirection();

	FRotator RotationAxis;
	FVector MoveDirection;
	FVector StartLocation;
	FVector EndLocation;
	bool bShouldReturn;

	FTimerHandle TimerHandle;
};
