// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameBoard.generated.h"

class UGameSpace;

/**
 * 
 */
UCLASS()
class ISIS_API UGameBoard : public UObject
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, Category = "GameBoard")
	UGameSpace* GetCoreGameSpace();

protected:

	void SetCoreGameSpace(UGameSpace* GameSpace);

private:
	
	UGameSpace* CoreGameSpace;
};
