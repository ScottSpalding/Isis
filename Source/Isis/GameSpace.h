// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameSpace.generated.h"

class AIsisPawn;

/**
 * 
 */
UCLASS(Blueprintable)
class ISIS_API AGameSpace : public AActor
{
	GENERATED_BODY()
	
public:
	
	UFUNCTION(BlueprintPure, Category = "GameBoard")
	TSet<AGameSpace*> GetAdjacentGameSpaces() const;

	UFUNCTION(BlueprintCallable, Category = "GameBoard")
	TSet<AGameSpace*> GetSpacesWithinRange(int32 Range);

	UFUNCTION(BlueprintCallable, Category = "GameBoard")
	void AddAdjacentGameSpace(AGameSpace* NewGameSpace);

	UFUNCTION(BlueprintPure, Category = "GameBoard")
	TSet<AIsisPawn*> GetPresentPawns() const;

	UFUNCTION(BlueprintCallable, Category = "GameBoard")
	void AddPresentPawn(AIsisPawn* AddedPawn);

	UFUNCTION(BlueprintCallable, Category = "GameBoard")
	void RemovePresentPawn(AIsisPawn* RemovedPawn);

private:

	TSet<AGameSpace*> AdjacentGameSpaces;

	TSet<AIsisPawn*> PresentPawns;

	TSet<AGameSpace*> GetSpacesWithinRangeHelper(AGameSpace* GameSpace, int32 Range);
};
