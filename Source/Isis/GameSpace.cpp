// Fill out your copyright notice in the Description page of Project Settings.

#include "GameSpace.h"

void AGameSpace::AddPresentPawn(AIsisPawn* AddedPawn)
{
	if (AddedPawn) {
		PresentPawns.Add(AddedPawn);
	}
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("Tried to add a null pawn to a game space.  Ignoring..."));
	}
}

void AGameSpace::RemovePresentPawn(AIsisPawn* RemovedPawn)
{
	if (RemovedPawn) {
		PresentPawns.Add(RemovedPawn);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Tried to remove a null pawn from a game space.  Ignoring..."));
	}
}

TSet<AItem*> AGameSpace::GetPresentItems() const
{
	return PresentItems;
}

void AGameSpace::AddPresentItem(AItem* AddedItem)
{
	PresentItems.Add(AddedItem);
}

void AGameSpace::RemovePresentItem(AItem* RemovedItem)
{
	PresentItems.Remove(RemovedItem);
}

TSet<AGameSpace*> AGameSpace::GetAdjacentGameSpaces() const
{
	return AdjacentGameSpaces;
}

TSet<AGameSpace*> AGameSpace::GetSpacesWithinRange(int32 Range)
{
	return GetSpacesWithinRangeHelper(this, Range);
}

TArray<AGameSpace*> AGameSpace::GetShortestPathToDestinationGameSpace(AGameSpace* DestinationGameSpace)
{
	TArray<AGameSpace*> PathOfGameSpaces;
	TArray<AGameSpace*> SearchedGameSpaces;

	if (this != DestinationGameSpace)
	{

	}

	return PathOfGameSpaces;
}

TSet<AGameSpace*> AGameSpace::GetSpacesWithinRangeHelper(AGameSpace* GameSpace, int32 Range)
{
	TSet<AGameSpace*> SpacesWithinRange;
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

void AGameSpace::AddAdjacentGameSpace(AGameSpace* NewGameSpace)
{
	AdjacentGameSpaces.Add(NewGameSpace);
}

TSet<AIsisPawn*> AGameSpace::GetPresentPawns() const
{
	return PresentPawns;
}
