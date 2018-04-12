// Fill out your copyright notice in the Description page of Project Settings.

#include "IsisGameMode.h"

#include "Engine/World.h"

#include "CombatEffect.h"
#include "GameBoard.h"
#include "GameSpace.h"
#include "IsisAIControllerRandom.h"
#include "IsisGameState.h"
#include "IsisPawn.h"
#include "Item.h"

void AIsisGameMode::SpawnNewIsisPawnInRandomLocation(AIsisPawn* NewPawn)
{
	auto AllGameSpaces = GetGameState<AIsisGameState>()->GetCurrentGameBoard()->GetAllGameSpaces();
		
	int RandomInteger = FMath::RandRange(0, AllGameSpaces.Num()-1);
	AGameSpace* NewGameSpace = AllGameSpaces.Array()[RandomInteger];

	NewPawn->SetCurrentGameSpace(NewGameSpace);
	NewGameSpace->AddPresentPawn(NewPawn);

	UE_LOG(LogTemp, Warning, TEXT("Spawned new pawn (%s) in location: %s"), *NewPawn->GetName(), *NewGameSpace->GetName());
}

void AIsisGameMode::SpawnNewEnemyInRandomLocation()
{
	UE_LOG(LogTemp, Warning, TEXT("Spawning new enemy pawn..."));
	AIsisPawn* NewPawn = GetWorld()->SpawnActor<AIsisPawn>();

	NewPawn->AIControllerClass = AIsisAIControllerRandom::StaticClass();
	NewPawn->SpawnDefaultController();

	NewPawn->EquipItem(GetRandomItemFromAllAvailable());

	SpawnNewIsisPawnInRandomLocation(NewPawn);
}

void AIsisGameMode::SpawnPlayerPawnInGivenLocation(AGameSpace * DesiredLocation)
{
	UE_LOG(LogTemp, Warning, TEXT("Spawning new player pawn..."));
	AIsisPawn* NewPawn = GetWorld()->SpawnActor<AIsisPawn>();

	NewPawn->SetCurrentGameSpace(DesiredLocation);
	//NewPawn->EquipItem(GetRandomItemFromAllAvailable());
	DesiredLocation->AddPresentPawn(NewPawn);
}

AItem* AIsisGameMode::GetRandomItemFromAllAvailable()
{
	const FString& ContextString = FString::Printf(TEXT("Failed getting all rows."));
	TArray<FItemType*> AllItemsArray;
	ItemTypeLookupTable->GetAllRows(ContextString, AllItemsArray);
	return MakeNewItemFromId(FMath::RandRange(1, AllItemsArray.Num()));
}

AItem* AIsisGameMode::MakeNewItemFromId(int32 DesiredId)
{
	AItem* NewItem = NewObject<AItem>();
	const FName DesiredIdAsFName = FName(*FString::FromInt(DesiredId));
	const FString& ContextFString = FString::Printf(TEXT("Tried creating missing item [%d]"), DesiredId);
	FItemType* DesiredItemType = ItemTypeLookupTable->FindRow<FItemType>(DesiredIdAsFName, ContextFString);
	if (DesiredItemType)
	{
		NewItem->CreateItemFromType(this, *DesiredItemType);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Could not find item with id: %d"), DesiredId);
	}

	return NewItem;
}

ACombatEffect* AIsisGameMode::MakeNewCombatEffectFromId(int32 DesiredId)
{
	FActorSpawnParameters spawnParams;
	spawnParams.Owner = this;
	FRotator rotator = FRotator(0.0f, 0.0f, 0.0f);
	FVector spawnLocation = FVector(0.0f, 0.0f, 0.0f);
	// check nullptr
	ACombatEffect* NewCombatEffect = GetWorld()->SpawnActor<ACombatEffect>(ToCreate, spawnLocation, rotator, spawnParams);
	if (NewCombatEffect) 
	{
		const FName DesiredIdAsFName = FName(*FString::FromInt(DesiredId));
		const FString& ContextFString = FString::Printf(TEXT("Tried creating missing effect [%d]"), DesiredId);
		FCombatEffectType* DesiredCombatEffectType = CombatEffectTypeLookupTable->FindRow<FCombatEffectType>(DesiredIdAsFName, ContextFString);
		if (DesiredCombatEffectType)
		{
			NewCombatEffect->CreateCombatEffectFromType(*DesiredCombatEffectType);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Could not find effect with id: %d"), DesiredId);
		}
	}
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("Why the fuck is this null?"));
	}

	return NewCombatEffect;
}
