// Fill out your copyright notice in the Description page of Project Settings.

#include "GameSpace.h"

void UGameSpace::AddPresentPawn(AIsisPawn* AddedPawn)
{
	if (AddedPawn) {
		PresentPawns.Add(AddedPawn);
	}
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("Tried to add a null pawn to a game space.  Ignoring..."));
	}
}

void UGameSpace::RemovePresentPawn(AIsisPawn* RemovedPawn)
{
	if (RemovedPawn) {
		PresentPawns.Add(RemovedPawn);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Tried to remove a null pawn from a game space.  Ignoring..."));
	}
}

TSet<UGameSpace*> UGameSpace::GetAdjacentGameSpaces() const
{
	return AdjacentGameSpaces;
}

void UGameSpace::AddAdjacentGameSpace(UGameSpace* NewGameSpace)
{
	AdjacentGameSpaces.Add(NewGameSpace);
}

TSet<AIsisPawn*> UGameSpace::GetPresentPawns() const
{
	return PresentPawns;
}
