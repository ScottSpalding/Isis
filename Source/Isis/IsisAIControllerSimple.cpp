// Fill out your copyright notice in the Description page of Project Settings.

#include "IsisAIControllerSimple.h"

#include "GameSpace.h"
#include "IsisPawn.h"

#include "Engine/World.h"

void AIsisAIControllerSimple::TakeTurn()
{
	auto PlayerPawn = static_cast<AIsisPawn*>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledPawn = static_cast<AIsisPawn*>(GetPawn());

	if (!(PlayerPawn && ControlledPawn)) { return; }

	if (!mHasScavenged) 
	{
		// Scavenge once
		auto currentGameSpace = ControlledPawn->GetCurrentGameSpace();
		int32 randomItemIndex = FMath::RandRange(0, currentGameSpace->GetPresentItems().Num() - 1);
		auto scavengedItem = currentGameSpace->GetPresentItems().Array()[randomItemIndex];
		currentGameSpace->RemovePresentItem(scavengedItem);
		ControlledPawn->EquipItem(scavengedItem);
		mHasScavenged = true;
	}
	else 
	{
		if (ControlledPawn->IsInAttackRange(PlayerPawn))
		{
			ControlledPawn->Attack(PlayerPawn);
		}
		else 
		{
			auto AdjacentGameSpaces = ControlledPawn->GetCurrentGameSpace()->GetAdjacentGameSpaces().Array();
			int32 randomGameSpaceIndex = FMath::RandRange(0, AdjacentGameSpaces.Num() - 1);
			ControlledPawn->MoveTo(AdjacentGameSpaces[randomGameSpaceIndex]);
		}
	}
}