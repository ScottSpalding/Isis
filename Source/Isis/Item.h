// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Engine/DataTable.h"
#include "GameFramework/Actor.h"

#include "Item.generated.h"

class ACombatEffect;
class AIsisGameMode;

UENUM(BlueprintType)
enum class EItemSlot : uint8
{
	NoSlot = 0,
	Head = 1,
	Chest = 2,
	LeftArm = 3,
	RightArm = 4,
	LeftLeg = 5,
	RightLeg = 6,
	LeftHand = 7,
	RightHand = 8,
};

USTRUCT(BlueprintType)
struct FItemType : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:

	FItemType() {}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CombatEffect")
	FText DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CombatEffect")
	uint8 FirstItemSlotId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CombatEffect")
	uint8 SecondItemSlotId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CombatEffect")
	bool IsConsumable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CombatEffect")
	int32 CombatEffectTypeId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CombatEffect")
	float ModifierValue;

	EItemSlot GetFirstItemSlot() const
	{
		return static_cast<EItemSlot>(FirstItemSlotId);
	}

	void SetFirstItemSlotId(EItemSlot NewItemSlot)
	{
		FirstItemSlotId = static_cast<uint8>(NewItemSlot);
	}

	EItemSlot GetSecondItemSlot() const
	{
		return static_cast<EItemSlot>(SecondItemSlotId);
	}

	void SetSecondItemSlotId(EItemSlot NewItemSlot)
	{
		SecondItemSlotId = static_cast<uint8>(NewItemSlot);
	}
};

UCLASS()
class ISIS_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

	UFUNCTION(BlueprintCallable, Category = "Item")
	void CreateItemFromType(AIsisGameMode* IsisGameMode, FItemType ItemType);

	UFUNCTION(BlueprintPure, Category = "Item")
	EItemSlot GetFirstItemSlot() const;

	UFUNCTION(BlueprintCallable, Category = "Item")
	void SetFirstItemSlot(EItemSlot NewFirstItemSlot);

	UFUNCTION(BlueprintPure, Category = "Item")
	EItemSlot GetSecondItemSlot() const;

	UFUNCTION(BlueprintCallable, Category = "Item")
	void SetSecondItemSlot(EItemSlot NewSecondItemSlot);

	UFUNCTION(BlueprintPure, Category = "Item")
	bool IsConsumable() const;

	UFUNCTION(BlueprintCallable, Category = "Item")
	void SetIsConsumable(bool NewIsConsumable);

	UFUNCTION(BlueprintPure, Category = "Item")
	ACombatEffect* GetCombatEffect() const;

	UFUNCTION(BlueprintCallable, Category = "Item")
	void SetCombatEffect(ACombatEffect* NewCombatEffect);

private:
	
	EItemSlot FirstItemSlot;
	EItemSlot SecondItemSlot;

	bool mIsConsumable;

	ACombatEffect* CombatEffect;

};
