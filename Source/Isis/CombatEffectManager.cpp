// Fill out your copyright notice in the Description page of Project Settings.

#include "CombatEffectManager.h"

#include "CombatEffect.h"

// Sets default values for this component's properties
UCombatEffectManager::UCombatEffectManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCombatEffectManager::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UCombatEffectManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

TSet<ACombatEffect*> UCombatEffectManager::GetActiveCombatEffects()
{
	return ActiveCombatEffects;
}

void UCombatEffectManager::AddCombatEffect(ACombatEffect* CombatEffect)
{
	ActiveCombatEffects.Add(CombatEffect);
	mDoCombatEffectsNeedRecalculated = true;
}

void UCombatEffectManager::RemoveCombatEffect(ACombatEffect* CombatEffect)
{
	ActiveCombatEffects.Remove(CombatEffect);
	mDoCombatEffectsNeedRecalculated = true;
}

void UCombatEffectManager::UpdateStats(AIsisPawn* PawnToApplyStatsTo)
{
	UE_LOG(LogTemp, Warning, TEXT("Updating stats."));
	mDoCombatEffectsNeedRecalculated = false;
	PawnToApplyStatsTo->ResetCurrentStats();
	// TODO sort CombatEffects to apply constants first, then multipliers
	for (ACombatEffect* CombatEffect : ActiveCombatEffects) 
	{
		UE_LOG(LogTemp, Warning, TEXT("Found effect, trying to broadcast."));
		CombatEffect->PersistentEffectDelegate.Broadcast(PawnToApplyStatsTo);
	}
	UE_LOG(LogTemp, Warning, TEXT("Done."));
}

bool UCombatEffectManager::DoCombatEffectsNeedRecalculated()
{
	return mDoCombatEffectsNeedRecalculated;
}

// TODO remove unused variables, functions, includes