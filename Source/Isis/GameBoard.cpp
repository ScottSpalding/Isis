// Fill out your copyright notice in the Description page of Project Settings.

#include "GameBoard.h"

UGameSpace* UGameBoard::GetCoreGameSpace() const
{
	return CoreGameSpace;
}

TSet<UGameSpace*> UGameBoard::GetAllGameSpaces() const
{
	return AllGameSpaces;
}

void UGameBoard::SetCoreGameSpace(UGameSpace * GameSpace)
{
	CoreGameSpace = GameSpace;
}
