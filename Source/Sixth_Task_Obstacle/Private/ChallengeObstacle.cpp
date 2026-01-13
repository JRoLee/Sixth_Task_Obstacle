#include "ChallengeObstacle.h"

#include "Animation/MovieScene2DTransformSection.h"

AChallengeObstacle::AChallengeObstacle()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);


	PrimaryActorTick.bCanEverTick = false;
}

void AChallengeObstacle::SetObstacleVisual(UStaticMesh* InMesh, UMaterialInterface* InMaterial)
{
	if (InMesh)
	{
		StaticMeshComp->SetStaticMesh(InMesh);
		StaticMeshComp->SetRelativeScale3D(FVector(50.0f));
	}

	if (InMaterial)
	{
		StaticMeshComp->SetMaterial(0, InMaterial);
	}
}

void AChallengeObstacle::BeginPlay()
{
	Super::BeginPlay();

	RandomAction();
}

void AChallengeObstacle::MoveObstacle()
{
	EndLocation = StartLocation + (MoveDirection.GetSafeNormal() * MaxRange);
	float ForwardMovedDistance = FVector::Dist(StartLocation, GetActorLocation());
	float BackwardMovedDistance = FVector::Dist(EndLocation, GetActorLocation());

	FVector DeltaLocation = MoveDirection * MoveSpeed;

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

void AChallengeObstacle::DestroyObstacle()
{
	Destroy(true);
}

void AChallengeObstacle::RotateObstacle()
{
	FRotator NewRotation = RotationAxis * RotationSpeed;
	AddActorLocalRotation(NewRotation);
}

void AChallengeObstacle::RandomAction()
{
	StartLocation = GetActorLocation();
	MoveDirection = GetRandomMoveDirection();
	RotationAxis = GetRandomRotationAxis();

	switch (FMath::RandRange(0, 2))
	{
	case 0:
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AChallengeObstacle::MoveObstacle, 0.01f, true);
		break;

	case 1:
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AChallengeObstacle::RotateObstacle, 0.01f, true);
		break;

	case 2:
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AChallengeObstacle::DestroyObstacle, 5.0f, false);
		break;

	default:
		break;
	}
}

FRotator AChallengeObstacle::GetRandomRotationAxis()
{
	int X = FMath::RandRange(-1, 1);
	int Y = FMath::RandRange(-1, 1);
	int Z = FMath::RandRange(-1, 1);

	return FRotator(X, Y, Z);
}

FVector AChallengeObstacle::GetRandomMoveDirection()
{
	int X = FMath::RandRange(-1, 1);
	int Y = FMath::RandRange(-1, 1);
	int Z = FMath::RandRange(-1, 1);

	return FVector(X, Y, Z);
}
