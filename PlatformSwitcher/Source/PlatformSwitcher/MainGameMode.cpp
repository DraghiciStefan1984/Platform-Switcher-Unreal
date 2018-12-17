// Fill out your copyright notice in the Description page of Project Settings.

#include "MainGameMode.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/Engine/Classes/Components/InputComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Runtime/Engine/Classes/GameFramework/Character.h"

void AMainGameMode::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetFirstPlayerController()->InputComponent->BindAction("Switch", IE_Pressed, this, &AMainGameMode::OnSwitch);
}

void AMainGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void AMainGameMode::OnSwitch()
{
	FVector location = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->GetActorLocation();

	if (switched)
	{
		location.X = 1200.0f;
	}
	else
	{
		location.X = 200.0f;
	}

	switched = !switched;

	UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->SetActorLocation(location);
}

void AMainGameMode::OnGameOver(bool win)
{
	UGameplayStatics::SetGamePaused(GetWorld(), win);
}