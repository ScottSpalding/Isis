// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameBoard.h"

#include "GameBoardThreeByThree.generated.h"

class AGameSpace;

/**
 * 
 */
UCLASS(Blueprintable)
class ISIS_API AGameBoardThreeByThree : public AGameBoard
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "GameBoard")
	int32 GetHeight();

	UFUNCTION(BlueprintCallable, Category = "GameBoard")
	int32 GetWidth();

	//UFUNCTION(BlueprintPure, Category = "GameBoard")
	//TArray<FInnerArray> GetGameBoardArray() const;

private:

	AGameBoardThreeByThree();

	int32 Height;
	int32 Width;

	//TArray<FInnerArray> GameBoard;
	
};
