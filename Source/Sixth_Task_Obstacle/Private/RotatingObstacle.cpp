#include "RotatingObstacle.h"

#include "ToolContextInterfaces.h"
#include "DataWrappers/ChaosVDParticleDataWrapper.h"
#include "Misc/MapErrors.h"

ARotatingObstacle::ARotatingObstacle()
{
 	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);
	
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);
	
	PrimaryActorTick.bCanEverTick = true;
	
	//UWorld::SpawnActor();
}

// Called when the game starts or when spawned
void ARotatingObstacle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARotatingObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	AddActorLocalRotation(FRotator(0.0f,RotationSpeed*DeltaTime,0.0f));

}

