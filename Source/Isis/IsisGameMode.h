// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "IsisGameMode.generated.h"

class AIsisPawn;

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

};
