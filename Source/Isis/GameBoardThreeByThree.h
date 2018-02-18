// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameBoard.h"
#include "GameBoardThreeByThree.generated.h"

/**
 * 
 */
UCLASS()
class ISIS_API UGameBoardThreeByThree : public UGameBoard
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, Category = "GameBoard")
	int32 GetHeight();

	UFUNCTION(BlueprintCallable, Category = "GameBoard")
	int32 GetWidth();

private:

	UGameBoardThreeByThree();

	int32 Height;
	int32 Width;
	
};
