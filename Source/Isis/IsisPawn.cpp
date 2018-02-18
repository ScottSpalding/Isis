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

void AIsisPawn::CauseDamage(int32 Damage)
{
	CurrentHealth -= Damage;
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
