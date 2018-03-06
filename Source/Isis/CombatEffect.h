// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "GameplayTagContainer.h"
#include "Engine/DataTable.h"

#include "IsisPawn.h"
#include "IsisPawnStat.h"

#include "CombatEffect.generated.h"

class AItem;

UENUM(BlueprintType)
enum class EPriorityType : uint8
{
	None = 0,
	Multiplier = 1,
	Constant = 2,
};

UENUM(BlueprintType)
enum class ERemoveableBy : uint8
{
	None = 0,
	Cleanse = 1,
};

USTRUCT(BlueprintType)
struct FCombatEffectType : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:

	FCombatEffectType() {}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CombatEffect")
	FName DebugName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CombatEffect")
	bool IsBeneficial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CombatEffect")
	bool CanStack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CombatEffect")
	bool CanExpire;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CombatEffect")
	uint8 DefaultNumberOfTurns;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CombatEffect")
	uint8 PriorityType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CombatEffect")
	uint8 RemoveableBy;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CombatEffect")
	uint8 StatAppliesTo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CombatEffect")
	uint8 StatModifierValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CombatEffect")
	FString Tags;

	EPriorityType GetPriorityType() const
	{
		return static_cast<EPriorityType>(PriorityType);
	}

	void SetPriorityType(EPriorityType NewPriorityType)
	{
		PriorityType = static_cast<uint8>(NewPriorityType);
	}

	ERemoveableBy GetRemoveableBy() const
	{
		return static_cast<ERemoveableBy>(RemoveableBy);
	}

	void SetRemoveableBy(ERemoveableBy NewRemoveableBy)
	{
		RemoveableBy = static_cast<uint8>(NewRemoveableBy);
	}

	EPawnStatType GetStatAppliesTo() const
	{
		return static_cast<EPawnStatType>(StatAppliesTo);
	}

	void SetStatAppliesTo(EPawnStatType NewStatAppliesTo)
	{
		StatAppliesTo = static_cast<uint8>(NewStatAppliesTo);
	}
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCombatEffectDelegate, AIsisPawn*, PawnToApplyCombatEffectTo);

UCLASS()
class ISIS_API ACombatEffect : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACombatEffect();

	UFUNCTION(BlueprintCallable, Category = "CombatEffect")
	void CreateCombatEffectFromType(FCombatEffectType CombatEffectType);

	UFUNCTION(BlueprintCallable, Category = "CombatEffect")
	void SetCombatEffectRequiredParameters(int NewTurnsLeftBeforeExpiration,
											bool IsBeneficial,
											bool CanStack,
											bool CanExpire,
											EPriorityType NewPriorityType,
											ERemoveableBy NewRemoveableBy);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintAssignable, Category = "CombatEffect")
	FCombatEffectDelegate EntryEffectDelegate;

	UPROPERTY(BlueprintAssignable, Category = "CombatEffect")
	FCombatEffectDelegate TickEffectDelegate;

	UPROPERTY(BlueprintAssignable, Category = "CombatEffect")
	FCombatEffectDelegate PersistentEffectDelegate;

	UPROPERTY(BlueprintAssignable, Category = "CombatEffect")
	FCombatEffectDelegate OnLeaveEffectDelegate;

	FGameplayTagContainer GameplayTags;

	UFUNCTION(BlueprintPure, Category = "CombatEffect")
	int GetTurnsLeftBeforeExpiration() const;

	UFUNCTION(BlueprintCallable, Category = "CombatEffect")
	void SetTurnsLeftBeforeExpiration(int TurnsLeft);

	UFUNCTION(BlueprintPure, Category = "CombatEffect")
	bool IsBeneficial() const;

	UFUNCTION(BlueprintCallable, Category = "CombatEffect")
	void SetIsBeneficial(bool IsBeneficial);

	UFUNCTION(BlueprintPure, Category = "CombatEffect")
	bool CanStack() const;

	UFUNCTION(BlueprintCallable, Category = "CombatEffect")
	void SetCanStack(bool CanStack);

	UFUNCTION(BlueprintPure, Category = "CombatEffect")
	bool CanExpire() const;

	UFUNCTION(BlueprintCallable, Category = "CombatEffect")
	void SetCanExpire(bool CanExpire);

	UFUNCTION(BlueprintPure, Category = "CombatEffect")
	float GetStatModifierValue() const;

	UFUNCTION(BlueprintCallable, Category = "CombatEffect")
	void SetStatModifierValue(float NewStatModifierValue);

	UFUNCTION(BlueprintPure, Category = "CombatEffect")
	EPawnStatType GetEffectedStatType() const;

	UFUNCTION(BlueprintCallable, Category = "CombatEffect")
	void SetEffectedStatType(EPawnStatType NewEffectedStatType);

	UFUNCTION(BlueprintPure, Category = "CombatEffect")
	AItem* GetOwningItem() const;

	UFUNCTION(BlueprintCallable, Category = "CombatEffect")
	void SetOwningItem(AItem* NewOwningItem);

private:

	float StatModifierValue;
	EPawnStatType EffectedStatType;

	// Effect Code
	int32 TurnsLeftBeforeExpiration;

	bool mIsBeneficial;
	bool mCanStack;
	bool mCanExpire;

	EPriorityType PriorityType;
	ERemoveableBy RemoveableBy;

	AItem* OwningItem;
};
