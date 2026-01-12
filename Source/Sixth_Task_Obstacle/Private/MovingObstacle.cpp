#include "MovingObstacle.h"

AMovingObstacle::AMovingObstacle()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	PrimaryActorTick.bCanEverTick = true;
}

void AMovingObstacle::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
	EndLocation = GetActorLocation() + FVector(MaxRange, 0.0f, 0.0f);
}

void AMovingObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float ForwardMovedDistance = FVector::Dist(StartLocation, GetActorLocation());
	float BackwardMovedDistance = FVector::Dist(EndLocation, GetActorLocation());

	FVector DeltaLocation(MoveSpeed * DeltaTime, 0.0f, 0.0f);

	if (ForwardMovedDistance >= MaxRange)
	{
		bShouldReturn = true;
	}
	else if (BackwardMovedDistance >= MaxRange)
	{
		bShouldReturn = false;
	}

	if (bShouldReturn == false)
	{
		AddActorWorldOffset(DeltaLocation);
	}
	else if (bShouldReturn == true)
	{
		AddActorWorldOffset(-DeltaLocation);
	}
}
