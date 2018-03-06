// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "IsisPawnStat.h"

#include "IsisPawnStats.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ISIS_API UIsisPawnStats : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UIsisPawnStats();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;		
	
	UFUNCTION(BlueprintCallable, Category = "Stats")
	int32 GetStatCurrentValue(EPawnStatType PawnStatType) const;

	UFUNCTION(BlueprintCallable, Category = "Stats")
	void SetCurrentStat(EPawnStatType PawnStatType, int32 NewStatValue);

	UFUNCTION(BlueprintCallable, Category = "Stats")
	void SetDefaultStat(EPawnStatType PawnStatType, int32 NewStatValue);

	UFUNCTION(BlueprintCallable, Category = "Stats")
	void ResetStats();

private:

	UPROPERTY(VisibleAnywhere, SimpleDisplay, Category = "Stats")
	TArray<UIsisPawnStat*> CurrentStats;

};
