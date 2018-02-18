// Fill out your copyright notice in the Description page of Project Settings.

#include "IsisPawn.h"

#include "GameSpace.h"

// Sets default values
AIsisPawn::AIsisPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

UGameSpace* AIsisPawn::GetCurrentGameSpace() const
{
	return CurrentGameSpace;
}

void AIsisPawn::SetCurrentGameSpace(UGameSpace * NewGameSpace)
{
	CurrentGameSpace = NewGameSpace;
}

bool AIsisPawn::MoveTo(UGameSpace* NewGameSpace)
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

	// Should we do sole source of truth instead of location?
	CurrentGameSpace->RemovePresentPawn(this);
	NewGameSpace->AddPresentPawn(this);
	CurrentGameSpace = NewGameSpace;

	return true;
}

int32 AIsisPawn::GetCurrentHealth() const
{
	return CurrentHealth;
}

int32 AIsisPawn::GetMaximumHealth() const
{
	return MaximumHealth;
}

bool AIsisPawn::Attack(AIsisPawn* TargetPawn)
{
	if (CurrentGameSpace->GetSpacesWithinRange(CurrentAttackRange).Contains(TargetPawn->GetCurrentGameSpace()))
	{
		TargetPawn->TakeDamage(CurrentAttackDamage);
		return true;
	}
	return false;
}

void AIsisPawn::TakeDamage(int32 Damage)
{
	int32 FinalDamage = ApplyArmorMitigation(ApplyReceivingDamageEffects(Damage));
	CurrentHealth -= FinalDamage;
	if (CurrentHealth < 0) 
	{
		CurrentHealth = 0;
	}
}

void AIsisPawn::HealDamage(int32 Damage)
{
	CurrentHealth += Damage;
	if (CurrentHealth > MaximumHealth)
	{
		CurrentHealth = MaximumHealth;
	}
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
