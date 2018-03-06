// Fill out your copyright notice in the Description page of Project Settings.

#include "CombatEffect.h"

#include "Engine/DataTable.h"
#include "Engine/World.h"

// Sets default values
ACombatEffect::ACombatEffect()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ACombatEffect::CreateCombatEffectFromType(FCombatEffectType CombatEffectType)
{
	TurnsLeftBeforeExpiration = CombatEffectType.DefaultNumberOfTurns;
	mIsBeneficial = CombatEffectType.IsBeneficial;
	mCanStack = CombatEffectType.CanStack;
	mCanExpire = CombatEffectType.CanExpire;
	PriorityType = CombatEffectType.GetPriorityType();
	RemoveableBy = CombatEffectType.GetRemoveableBy();
	StatModifierValue = CombatEffectType.StatModifierValue;
	EffectedStatType = CombatEffectType.GetStatAppliesTo();;

}

// TODO refactor two constructors together

void ACombatEffect::SetCombatEffectRequiredParameters(int NewTurnsLeftBeforeExpiration, bool IsBeneficial, bool CanStack, bool CanExpire, EPriorityType NewPriorityType, ERemoveableBy NewRemoveableBy)
{
	TurnsLeftBeforeExpiration = NewTurnsLeftBeforeExpiration;
	mIsBeneficial = IsBeneficial;
	mCanStack = CanStack;
	mCanExpire = CanExpire;
	PriorityType = NewPriorityType;
	RemoveableBy = NewRemoveableBy;
}

// Called when the game starts or when spawned
void ACombatEffect::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACombatEffect::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

int ACombatEffect::GetTurnsLeftBeforeExpiration() const
{
	return 0;
}

void ACombatEffect::SetTurnsLeftBeforeExpiration(int TurnsLeft)
{
}

bool ACombatEffect::IsBeneficial() const
{
	return mIsBeneficial;
}

void ACombatEffect::SetIsBeneficial(bool IsBeneficial)
{
	mIsBeneficial = IsBeneficial;
}

bool ACombatEffect::CanStack() const
{
	return mCanStack;
}

void ACombatEffect::SetCanStack(bool CanStack)
{
	mCanStack = CanStack;
}

bool ACombatEffect::CanExpire() const
{
	return mCanExpire;
}

void ACombatEffect::SetCanExpire(bool CanExpire)
{
	mCanExpire = CanExpire;
}

float ACombatEffect::GetStatModifierValue() const
{
	return StatModifierValue;
}

void ACombatEffect::SetStatModifierValue(float NewStatModifierValue)
{
	StatModifierValue = NewStatModifierValue;
}

EPawnStatType ACombatEffect::GetEffectedStatType() const
{
	return EffectedStatType;
}

void ACombatEffect::SetEffectedStatType(EPawnStatType NewEffectedStatType)
{
	EffectedStatType = NewEffectedStatType;
}

AItem * ACombatEffect::GetOwningItem() const
{
	return OwningItem;
}

void ACombatEffect::SetOwningItem(AItem * NewOwningItem)
{
	OwningItem = NewOwningItem;
}

