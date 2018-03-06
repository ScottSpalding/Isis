// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"

#include "Engine/DataTable.h"

#include "IsisGameMode.generated.h"

class AIsisPawn;
class AGameSpace;
class ACombatEffect;
class AItem;

/**
 * 
 */
UCLASS()
class ISIS_API AIsisGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, Category = "GameBoard")
	void SpawnNewIsisPawnInRandomLocation(AIsisPawn* NewPawn);
	
	UFUNCTION(BlueprintCallable, Category = "GameBoard")
	void SpawnNewEnemyInRandomLocation();

	UFUNCTION(BlueprintCallable, Category = "GameBoard")
	void SpawnPlayerPawnInGivenLocation(AGameSpace* DesiredLocation);

	UFUNCTION(BlueprintCallable, Category = "Item")
	AItem* GetRandomItemFromAllAvailable();

	UFUNCTION(BlueprintCallable, Category = "Item")
	AItem* MakeNewItemFromId(int32 DesiredId);

	UFUNCTION(BlueprintCallable, Category = "CombatEffect")
	ACombatEffect* MakeNewCombatEffectFromId(int32 DesiredId);

	UPROPERTY(EditAnywhere)
	UDataTable* CombatEffectTypeLookupTable;

	UPROPERTY(EditAnywhere)
	UDataTable* ItemTypeLookupTable;

	UPROPERTY(EditAnywhere)
	TSubclassOf<ACombatEffect> ToCreate;
};
