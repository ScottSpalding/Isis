// Fill out your copyright notice in the Description page of Project Settings.

#include "Item.h"

#include "Engine/World.h"

#include "CombatEffect.h"
#include "IsisGameMode.h"

// Sets default values
AItem::AItem()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void AItem::CreateItemFromType(AIsisGameMode* IsisGameMode, FItemType ItemType)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	FirstItemSlot = ItemType.GetFirstItemSlot();
	SecondItemSlot = ItemType.GetSecondItemSlot();
	mIsConsumable = ItemType.IsConsumable;
	CombatEffect = IsisGameMode->MakeNewCombatEffectFromId(ItemType.CombatEffectTypeId);
	if (CombatEffect)
	{
		CombatEffect->SetOwningItem(this);
	} else 
	{
		UE_LOG(LogTemp, Warning, TEXT("Why the fuck is this null?"));
	}

}

EItemSlot AItem::GetFirstItemSlot() const
{
	return FirstItemSlot;
}

void AItem::SetFirstItemSlot(EItemSlot NewFirstItemSlot)
{
	FirstItemSlot = NewFirstItemSlot;
}

EItemSlot AItem::GetSecondItemSlot() const
{
	return SecondItemSlot;
}

void AItem::SetSecondItemSlot(EItemSlot NewSecondItemSlot)
{
	SecondItemSlot = NewSecondItemSlot;
}

bool AItem::IsConsumable() const
{
	return mIsConsumable;
}

void AItem::SetIsConsumable(bool NewIsConsumable)
{
	mIsConsumable = NewIsConsumable;
}

ACombatEffect* AItem::GetCombatEffect() const
{
	return CombatEffect;
}

void AItem::SetCombatEffect(ACombatEffect* NewCombatEffect)
{
	CombatEffect = NewCombatEffect;
}
