// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameBoard.generated.h"

class AGameSpace;
//
//USTRUCT(BlueprintType)
//struct FInnerArray
//{
//	GENERATED_BODY()
//
//	UPROPERTY(BlueprintReadOnly, Category = "GameBoard")
//	TArray<AGameSpace *> GameSpaces;
//};

/**
 * 
 */
UCLASS()
class ISIS_API AGameBoard : public AActor
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintPure, Category = "GameBoard")
	AGameSpace* GetCoreGameSpace() const;

	UFUNCTION(BlueprintCallable, Category = "GameBoard")
	void SetCoreGameSpace(AGameSpace* NewCoreSpace);

	UFUNCTION(BlueprintCallable, Category = "GameBoard")
	void AddGameSpace(AGameSpace* NewCoreSpace);

	UFUNCTION(BlueprintPure, Category = "GameBoard")
	TSet<AGameSpace*> GetAllGameSpaces() const;
/*
	UFUNCTION(BlueprintPure, Category = "GameBoard")
	TArray<FInnerArray> GetGameBoardArray() const;*/

protected:

	TSet<AGameSpace*> AllGameSpaces;
	AGameSpace CoreGameSpace;

};
