// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IsisPawnStat.generated.h"

UENUM(BlueprintType)
enum class EPawnStatType : uint8
{
	None = 0,
	MaximumHealth = 1,
	AttackDamage = 2,
	MovementInSquares = 3,
};

/**
 * 
 */
UCLASS()
class ISIS_API UIsisPawnStat : public UObject
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, Category = "Stats")
	EPawnStatType GetStatType() const;

	UFUNCTION(BlueprintCallable, Category = "Stats")
	int32 GetCurrentStatValue() const;

	UFUNCTION(BlueprintCallable, Category = "Stats")
	void SetCurrentStatValue(int32 NewValue);

	UFUNCTION(BlueprintCallable, Category = "Stats")
	void SetStatType(EPawnStatType NewStatType);

	UFUNCTION(BlueprintCallable, Category = "Stats")
	void SetDefaultStat(int32 NewDefaultStatValue);

	UFUNCTION(BlueprintCallable, Category = "Stats")
	void ResetStat();

private:

	UPROPERTY(VisibleAnywhere, SimpleDisplay, Category = "Stats")
	EPawnStatType StatType = EPawnStatType::None;

	UPROPERTY(VisibleAnywhere, SimpleDisplay, Category = "Stats")
	int32 CurrentStatValue = 0;

	UPROPERTY(VisibleAnywhere, SimpleDisplay, Category = "Stats")
	int32 DefaultStatValue = 0;	
};
