#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingObstacle.generated.h"

UCLASS()
class SIXTH_TASK_OBSTACLE_API ARotatingObstacle : public AActor
{
	GENERATED_BODY()
	
public:	

	ARotatingObstacle();

protected:

	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Rotating Obstacle|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Rotating Obstacle|Components")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Rotating Obstacle|Properties")
	float RotationSpeed;
	
	
	
public:	

	virtual void Tick(float DeltaTime) override;

};
