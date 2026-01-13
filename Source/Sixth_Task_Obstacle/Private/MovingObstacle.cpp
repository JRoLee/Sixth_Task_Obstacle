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
}

void AMovingObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	EndLocation = StartLocation + MoveDirection * MaxRange;
	float ForwardMovedDistance = FVector::Dist(StartLocation, GetActorLocation());
	float BackwardMovedDistance = FVector::Dist(EndLocation, GetActorLocation());

	FVector DeltaLocation = MoveDirection * MoveSpeed * DeltaTime;

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
