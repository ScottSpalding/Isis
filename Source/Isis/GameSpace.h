// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameSpace.generated.h"

class AIsisPawn;

/**
 * 
 */
UCLASS()
class ISIS_API UGameSpace : public UObject
{
	GENERATED_BODY()
	
public:
	
	UFUNCTION(BlueprintPure, Category = "GameBoard")
	TSet<UGameSpace*> GetAdjacentGameSpaces() const;

	UFUNCTION(BlueprintCallable, Category = "GameBoard")
	TSet<UGameSpace*> GetSpacesWithinRange(int32 Range);

	UFUNCTION(BlueprintCallable, Category = "GameBoard")
	void AddAdjacentGameSpace(UGameSpace* NewGameSpace);

	UFUNCTION(BlueprintPure, Category = "GameBoard")
	TSet<AIsisPawn*> GetPresentPawns() const;

	UFUNCTION(BlueprintCallable, Category = "GameBoard")
	void AddPresentPawn(AIsisPawn* AddedPawn);

	UFUNCTION(BlueprintCallable, Category = "GameBoard")
	void RemovePresentPawn(AIsisPawn* RemovedPawn);

private:

	TSet<UGameSpace*> AdjacentGameSpaces;

	TSet<AIsisPawn*> PresentPawns;

	TSet<UGameSpace*> GetSpacesWithinRangeHelper(UGameSpace* GameSpace, int32 Range);
};
