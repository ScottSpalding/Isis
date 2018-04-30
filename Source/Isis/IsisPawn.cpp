// Fill out your copyright notice in the Description page of Project Settings.

#include "IsisPawn.h"

#include "CombatEffectManager.h"
#include "GameSpace.h"
#include "Item.h"
#include "IsisPawnStats.h"
#include "IsisPawnStat.h"

// Sets default values
AIsisPawn::AIsisPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	UCombatEffectManager* NewCombatEffectManager = CreateDefaultSubobject<UCombatEffectManager>(TEXT("CombatEffectManager"));
	CombatEffectManager = NewCombatEffectManager;

	UIsisPawnStats* NewCurrentStats = CreateDefaultSubobject<UIsisPawnStats>(TEXT("CurrentStats"));
	CurrentStats = NewCurrentStats;
	CurrentStats->SetDefaultStat(EPawnStatType::MaximumHealth, BaseMaximumHealth);
	CurrentStats->SetDefaultStat(EPawnStatType::MovementInSquares, BaseMovement);
	CurrentStats->SetDefaultStat(EPawnStatType::AttackDamage, BaseAttackDamage);

	//CombatEffectManager->UpdateStats(this);
}

// Called when the game starts or when spawned
void AIsisPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AIsisPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

AGameSpace* AIsisPawn::GetCurrentGameSpace() const
{
	return CurrentGameSpace;
}

void AIsisPawn::SetCurrentGameSpace(AGameSpace * NewGameSpace)
{
	CurrentGameSpace = NewGameSpace;
}

bool AIsisPawn::MoveTo(AGameSpace* NewGameSpace)
{
	// TODO refactor to use IsLegalMove
	if (!NewGameSpace) 
	{
		UE_LOG(LogTemp, Warning, TEXT("Tried to move to a null space as %s."), *GetName());
		return false;
	}

	if (!CurrentGameSpace->GetAdjacentGameSpaces().Contains(NewGameSpace)) 
	{
		UE_LOG(LogTemp, Warning, TEXT("%s tried to move to out of range space: %s"), *GetName(), *NewGameSpace->GetName());
		return false;
	}

	// Should we do sole source of truth instead of location?
	CurrentGameSpace->RemovePresentPawn(this);
	NewGameSpace->AddPresentPawn(this);
	CurrentGameSpace = NewGameSpace;

	return true;
}

bool AIsisPawn::IsLegalMove(AGameSpace * NewGameSpace)
{
	if (!NewGameSpace)
	{
		UE_LOG(LogTemp, Warning, TEXT("Tried to move to a null space as %s."), *GetName());
		return false;
	}

	if (!CurrentGameSpace->GetAdjacentGameSpaces().Contains(NewGameSpace))
	{
		UE_LOG(LogTemp, Warning, TEXT("%s tried to move to out of range space: %s"), *GetName(), *NewGameSpace->GetName());
		return false;
	}

	return true;
}

int32 AIsisPawn::GetCurrentHealth() const
{
	return CurrentStats->GetStatCurrentValue(EPawnStatType::MaximumHealth);
}
//
//int32 AIsisPawn::GetMaximumHealth() const
//{
//	int32 CurrentMaximumHealth = CombatEffectManager->GetMaximumHealth(BaseMaximumHealth);
//	return CurrentMaximumHealth;
//}

bool AIsisPawn::IsInAttackRange(AIsisPawn* TargetPawn)
{
	if (CurrentGameSpace->GetSpacesWithinRange(BaseAttackRange).Contains(TargetPawn->GetCurrentGameSpace()))
	{
		return true;
	}
	return false;
}

bool AIsisPawn::Attack(AIsisPawn* TargetPawn)
{
	if (CurrentGameSpace->GetSpacesWithinRange(BaseAttackRange).Contains(TargetPawn->GetCurrentGameSpace()))
	{
		//TargetPawn->TakeDamage(BaseAttackDamage);
		return true;
	}
	return false;
}

//void AIsisPawn::TakeDamage(int32 Damage)
//{
//	int32 FinalDamage = ApplyArmorMitigation(ApplyReceivingDamageEffects(Damage));
//	//CurrentStats.CurrentHealth -= FinalDamage;
//	//if (CurrentStats.CurrentHealth < 0)
//	//{
//	//	CurrentStats.CurrentHealth = 0;
//	//}
//}

void AIsisPawn::HealDamage(int32 Damage)
{
	//CurrentStats.CurrentHealth += Damage;
	//int32 CurrentMaximumHealth = CurrentStats.MaximumHealth;
	//if (CurrentStats.CurrentHealth > CurrentMaximumHealth)
	//{
	//	CurrentStats.CurrentHealth = CurrentMaximumHealth;
	//}
}

UCombatEffectManager * AIsisPawn::GetCombatEffectManager() const
{
	return CombatEffectManager;
}

void AIsisPawn::UnequipItem(AItem* UnequippedItem)
{
	EquippedItems.Remove(UnequippedItem);
	CombatEffectManager->RemoveCombatEffect(UnequippedItem->GetCombatEffect());
}

UIsisPawnStats* AIsisPawn::GetCurrentStats()
{
	if (CombatEffectManager->DoCombatEffectsNeedRecalculated())
	{
		CombatEffectManager->UpdateStats(this);
	}
	return CurrentStats;
}

void AIsisPawn::ResetCurrentStats()
{
	CurrentStats->ResetStats();
}

void AIsisPawn::EquipItem(AItem* EquippedItem)
{
	EquippedItems.Add(EquippedItem);
	CombatEffectManager->AddCombatEffect(EquippedItem->GetCombatEffect());
	CombatEffectManager->UpdateStats(this);
}

int AIsisPawn::ApplyArmorMitigation(int32 Damage)
{
	// Currently armor doesn't exist, so no mitigation
	return Damage;
}

int AIsisPawn::ApplyReceivingDamageEffects(int32 Damage)
{
	// Currently damage effects don't exist, so no effects
	return Damage;
}
