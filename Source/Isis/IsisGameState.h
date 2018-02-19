// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "IsisGameState.generated.h"

class AGameBoard;

/**
 * 
 */
UCLASS()
class ISIS_API AIsisGameState : public AGameState
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "GameBoard")
	AGameBoard* GetCurrentGameBoard();

	UFUNCTION(BlueprintCallable, Category = "GameBoard")
	void SetCurrentGameBoard(AGameBoard* NewGameBoard);

	UFUNCTION(BlueprintCallable, Category = "IsisGame")
	void ResetGameState();

private:

	AGameBoard* CurrentGameBoard;
	
};
