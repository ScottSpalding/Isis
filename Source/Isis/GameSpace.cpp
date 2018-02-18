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

TSet<UGameSpace*> UGameSpace::GetSpacesWithinRange(int32 Range)
{
	return GetSpacesWithinRangeHelper(this, Range);
}

TSet<UGameSpace*> UGameSpace::GetSpacesWithinRangeHelper(UGameSpace* GameSpace, int32 Range)
{
	TSet<UGameSpace*> SpacesWithinRange;
	if (Range == 0) 
	{
	}
	else if (Range == 1)
	{
		SpacesWithinRange.Append(GameSpace->GetAdjacentGameSpaces());
	}
	else
	{
		SpacesWithinRange.Append(GameSpace->GetAdjacentGameSpaces());
		for (auto& GameSpaceToCheck : GameSpace->GetAdjacentGameSpaces())
		{
			SpacesWithinRange.Append(GetSpacesWithinRangeHelper(GameSpaceToCheck, Range));
		}
	}
	return SpacesWithinRange;
}

void UGameSpace::AddAdjacentGameSpace(UGameSpace* NewGameSpace)
{
	AdjacentGameSpaces.Add(NewGameSpace);
}

TSet<AIsisPawn*> UGameSpace::GetPresentPawns() const
{
	return PresentPawns;
}
