// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "IsisPawn.generated.h"

class AGameSpace;

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

	void SetCurrentGameSpace(AGameSpace* NewGameSpace);

	UFUNCTION(BlueprintCallable, Category = "GameBoard")
	bool MoveTo(AGameSpace* NewGameSpace);

	UFUNCTION(BlueprintPure, Category = "Health")
	int32 GetCurrentHealth() const;

	UFUNCTION(BlueprintPure, Category = "Health")
	int32 GetMaximumHealth() const;

	UFUNCTION(BlueprintCallable, Category = "Attack")
	bool Attack(AIsisPawn * TargetPawn);

	UFUNCTION(BlueprintCallable, Category = "Health")
	void TakeDamage(int32 Damage);

	UFUNCTION(BlueprintCallable, Category = "Health")
	void HealDamage(int32 Damage);

private:

	AGameSpace* CurrentGameSpace;
	
	int32 MaximumHealth = 10;
	int32 CurrentHealth = 10;

	int32 CurrentAttackRange = 1;
	int32 CurrentAttackDamage = 3;

	int ApplyArmorMitigation(int32 Damage);
	int ApplyReceivingDamageEffects(int32 Damage);

};