// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "IsisPawn.generated.h"

class AGameSpace;
class AItem;
class UCombatEffectManager;
class UIsisPawnStats;

//UENUM(BlueprintType)
//enum class EPawnStatType : uint8
//{
//	None = 0,
//	MaximumHealth = 1,
//	AttackDamage = 2,
//	MovementInSquares = 3,
//};
//
//// TODO Refactor to being object-driven
//USTRUCT(BlueprintType)
//struct FIsisPawnStat
//{
//	GENERATED_USTRUCT_BODY()
//
//public:
//
//	FIsisPawnStat() {}
//
//	FIsisPawnStat(EPawnStatType NewStatType, int32 NewDefaultStatValue) 
//	{
//		StatType = NewStatType;
//		DefaultStatValue = NewDefaultStatValue;
//		DefaultStatValue = NewDefaultStatValue;
//	}
//
//	UPROPERTY(VisibleAnywhere, SimpleDisplay, Category = "Stats")
//	EPawnStatType StatType = EPawnStatType::None;
//
//	UPROPERTY(VisibleAnywhere, SimpleDisplay, Category = "Stats")
//	int32 CurrentStatValue = 0;
//
//	UPROPERTY(VisibleAnywhere, SimpleDisplay, Category = "Stats")
//	int32 DefaultStatValue = 0;
//
//	void SetStatType(EPawnStatType NewStatType)
//	{
//		StatType = NewStatType;
//	}
//
//	void SetDefaultStat(int32 NewDefaultStatValue)
//	{
//		DefaultStatValue = NewDefaultStatValue;
//	}
//
//	void ResetStat()
//	{
//		CurrentStatValue = DefaultStatValue;
//	}
//};


//USTRUCT(BlueprintType)
//struct FIsisPawnStats
//{
//	GENERATED_USTRUCT_BODY()
//
//public:
//
//	FIsisPawnStats() {}
//
//	UPROPERTY(VisibleAnywhere, SimpleDisplay, Category = "Stats")
//	TArray<FIsisPawnStat> CurrentStats;
//
//	int32 GetStatCurrentValue(EPawnStatType PawnStatType) const
//	{
//		for (FIsisPawnStat CurrentStat : CurrentStats)
//		{
//			if (CurrentStat.StatType == PawnStatType) 
//			{
//				return CurrentStat.CurrentStatValue;
//			}
//		}
//		// TODO We need a stat, so getting here is super bad, but return Int32 will  have terrible results.
//		return INT32_MAX;
//	}
//
//	void SetCurrentStat(EPawnStatType PawnStatType, int32 NewStatValue) 
//	{
//		FIsisPawnStat NewStat = FIsisPawnStat(PawnStatType, NewStatValue);
//		CurrentStats.Add(NewStat);
//	}
//
//	void SetDefaultStat(EPawnStatType PawnStatType, int32 NewStatValue)
//	{
//		/*auto OldStatPointer = CurrentStats.FindByPredicate([PawnStatType](const FIsisPawnStat& StatToCheck)
//		{
//			return StatToCheck.StatType == PawnStatType;
//		});
//		if (OldStatPointer)
//		{
//		}*/
//
//		// TODO make better
//		int32 FoundIndex = -1;
//		for (int32 Index = 0; Index < CurrentStats.Num() - 1; Index++)
//		{
//			if (CurrentStats[Index].StatType == PawnStatType)
//			{
//				FoundIndex = Index;
//				break;
//			}
//		}
//		if (FoundIndex != -1)
//		{
//			CurrentStats.RemoveAt(FoundIndex);
//		}
//
//		FIsisPawnStat NewStat = FIsisPawnStat(PawnStatType, NewStatValue);
//		CurrentStats.Add(NewStat);
//	}
//
//	void ResetStats()
//	{
//		for (FIsisPawnStat CurrentStat : CurrentStats)
//		{
//			CurrentStat.ResetStat();
//		}
//	}
//};

UCLASS()
class ISIS_API AIsisPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AIsisPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintPure, Category = "GameBoard")
	AGameSpace* GetCurrentGameSpace() const;

	UFUNCTION(BlueprintCallable, Category = "GameBoard")
	void SetCurrentGameSpace(AGameSpace* NewGameSpace);

	UFUNCTION(BlueprintCallable, Category = "GameBoard")
	bool MoveTo(AGameSpace* NewGameSpace);

	UFUNCTION(BlueprintCallable, Category = "GameBoard")
	bool IsLegalMove(AGameSpace* NewGameSpace);

	// TODO check int types to make sure they're the right size

	UFUNCTION(BlueprintPure, Category = "Stats")
	int32 GetCurrentHealth() const;

	//UFUNCTION(BlueprintPure, Category = "Stats")
	//int32 GetMaximumHealth() const;

	UFUNCTION(BlueprintCallable, Category = "GameBoard")
	bool IsInAttackRange(AIsisPawn* TargetPawn);

	UFUNCTION(BlueprintCallable, Category = "GameBoard")
	bool Attack(AIsisPawn* TargetPawn);

	UFUNCTION(BlueprintCallable, Category = "Stats")
	void TakeDamage(int32 Damage);

	UFUNCTION(BlueprintCallable, Category = "Stats")
	void HealDamage(int32 Damage);

	UFUNCTION(BlueprintPure, Category = "Stats")
	UCombatEffectManager* GetCombatEffectManager() const;

	UFUNCTION(BlueprintCallable, Category = "Stats")
	void EquipItem(AItem* UnequippedItem);

	UFUNCTION(BlueprintCallable, Category = "Stats")
	void UnequipItem(AItem* EquippedItem);

	UFUNCTION(BlueprintCallable, Category = "Stats")
	UIsisPawnStats* GetCurrentStats();

	UFUNCTION(BlueprintCallable, Category = "Stats")
	void ResetCurrentStats();

private:

	UPROPERTY(VisibleAnywhere, SimpleDisplay, Category = "GameBoard")
	AGameSpace* CurrentGameSpace;
	
	UPROPERTY(VisibleAnywhere, SimpleDisplay, Category = "Stats")
	int32 BaseMaximumHealth = 10;

	UPROPERTY(VisibleAnywhere, SimpleDisplay, Category = "Stats")
	int32 BaseAttackRange = 1;

	UPROPERTY(VisibleAnywhere, SimpleDisplay, Category = "Stats")
	int32 BaseMovement = 1;

	UPROPERTY(VisibleAnywhere, SimpleDisplay, Category = "Stats")
	int32 BaseAttackDamage = 3;

	UPROPERTY(VisibleAnywhere, SimpleDisplay, Category = "Stats")
	UCombatEffectManager* CombatEffectManager;

	UPROPERTY(VisibleAnywhere, SimpleDisplay, Category = "Stats")
	TSet<AItem*> EquippedItems;

	UPROPERTY(VisibleAnywhere, SimpleDisplay, Category = "Stats")
	UIsisPawnStats* CurrentStats;

	int ApplyArmorMitigation(int32 Damage);
	int ApplyReceivingDamageEffects(int32 Damage);

};