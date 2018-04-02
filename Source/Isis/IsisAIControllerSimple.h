// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IsisAIController.h"
#include "IsisAIControllerSimple.generated.h"

/**
 * 
 */
UCLASS()
class ISIS_API AIsisAIControllerSimple : public AIsisAIController
{
	GENERATED_BODY()
	
public:

	void TakeTurn();
	
private:

	bool mHasScavenged = false;
};
