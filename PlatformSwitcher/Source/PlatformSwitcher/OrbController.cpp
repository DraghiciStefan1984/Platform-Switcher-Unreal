// Fill out your copyright notice in the Description page of Project Settings.

#include "OrbController.h"
#include "Runtime/Engine/Classes/Components/BoxComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/GameFramework/Character.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "MainGameMode.h"

// Sets default values
AOrbController::AOrbController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	rootBox = CreateDefaultSubobject<UBoxComponent>(TEXT("root"));
	rootBox->SetGenerateOverlapEvents(true);
	rootBox->OnComponentBeginOverlap.AddDynamic(this, &AOrbController::OnOverlap);
	RootComponent = rootBox;
}

// Called when the game starts or when spawned
void AOrbController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOrbController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AOrbController::OnOverlap(UPrimitiveComponent * overlapComponent, AActor * otherActor, UPrimitiveComponent * otherComponent, int32 otherBodyIndex, bool bFromSweep, const FHitResult & sweepResult)
{
	if (otherActor == UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))
	{
		((AMainGameMode*)GetWorld()->GetAuthGameMode())->OnGameOver(true);
	}
}


