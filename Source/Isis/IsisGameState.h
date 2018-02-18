// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "IsisGameState.generated.h"

class UGameBoard;

/**
 * 
 */
UCLASS()
class ISIS_API AIsisGameState : public AGameState
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable, Category = "GameBoard")
	UGameBoard* GetCurrentGameBoard();

	UFUNCTION(BlueprintCallable, Category = "IsisGame")
	void ResetGameState();

private:

	UGameBoard* CurrentGameBoard;
	
};
