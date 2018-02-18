// Fill out your copyright notice in the Description page of Project Settings.

#include "IsisGameMode.h"

#include "Engine/World.h"

#include "GameBoard.h"
#include "GameSpace.h"
#include "IsisAIControllerRandom.h"
#include "IsisGameState.h"
#include "IsisPawn.h"

void AIsisGameMode::SpawnNewIsisPawnInRandomLocation(AIsisPawn* NewPawn)
{
	auto AllGameSpaces = GetGameState<AIsisGameState>()->GetCurrentGameBoard()->GetAllGameSpaces();
		
	int RandomInteger = FMath::RandRange(0, AllGameSpaces.Num()-1);
	UGameSpace* NewGameSpace = AllGameSpaces.Array()[RandomInteger];

	NewPawn->SetCurrentGameSpace(NewGameSpace);
	NewGameSpace->AddPresentPawn(NewPawn);

	UE_LOG(LogTemp, Warning, TEXT("Spawned new pawn (%s) in location: %s"), *NewPawn->GetName(), *NewGameSpace->GetName());
}

void AIsisGameMode::SpawnNewEnemyInRandomLocation()
{
	UE_LOG(LogTemp, Warning, TEXT("Spawning new enemy..."));
	AIsisPawn* NewPawn = GetWorld()->SpawnActor<AIsisPawn>();
	NewPawn->AIControllerClass = AIsisAIControllerRandom::StaticClass();
	NewPawn->SpawnDefaultController();
	SpawnNewIsisPawnInRandomLocation(NewPawn);
}
