// Fill out your copyright notice in the Description page of Project Settings.

#include "ObstacleController.h"
#include "Runtime/Engine/Classes/Components/BoxComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/GameFramework/Character.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "MainGameMode.h"

// Sets default values
AObstacleController::AObstacleController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	rootBox = CreateDefaultSubobject<UBoxComponent>(TEXT("root"));
	rootBox->SetGenerateOverlapEvents(true);
	rootBox->OnComponentBeginOverlap.AddDynamic(this, &AObstacleController::OnOverlap);
	RootComponent = rootBox;
}

// Called when the game starts or when spawned
void AObstacleController::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AObstacleController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AObstacleController::OnOverlap(UPrimitiveComponent * overlapComponent, AActor * otherActor, UPrimitiveComponent * otherComponent, int32 otherBodyIndex, bool bFromSweep, const FHitResult & sweepResult)
{
	if (otherActor == UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))
	{
		((AMainGameMode*)GetWorld()->GetAuthGameMode())->OnGameOver(false);
	}
}

