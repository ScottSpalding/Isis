// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Components/ActorComponent.h"

#include "IsisPawn.h"

#include "CombatEffectManager.generated.h"

class ACombatEffect;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ISIS_API UCombatEffectManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCombatEffectManager();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "CombatEffect")
	TSet<ACombatEffect*> GetActiveCombatEffects();

	UFUNCTION(BlueprintCallable, Category = "CombatEffect")
	void AddCombatEffect(ACombatEffect* CombatEffect);

	UFUNCTION(BlueprintCallable, Category = "CombatEffect")
	void RemoveCombatEffect(ACombatEffect* CombatEffect);

	UFUNCTION(BlueprintCallable, Category = "Stats")
	void UpdateStats(AIsisPawn* PawnToApplyStatsTo);

	UFUNCTION(BlueprintCallable, Category = "Stats")
	bool DoCombatEffectsNeedRecalculated();

private:
	
	UPROPERTY(VisibleAnywhere, SimpleDisplay, Category = "CombatEffect")
	TSet<ACombatEffect*> ActiveCombatEffects;

	UPROPERTY(VisibleAnywhere, SimpleDisplay, Category = "CombatEffect")
	bool mDoCombatEffectsNeedRecalculated = false;
};
