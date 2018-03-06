// Fill out your copyright notice in the Description page of Project Settings.

#include "GameBoard.h"

AGameSpace* AGameBoard::GetCoreGameSpace() const
{
	return CoreGameSpace;
}

TSet<AGameSpace*> AGameBoard::GetAllGameSpaces() const
{
	return AllGameSpaces;
}

void AGameBoard::SetCoreGameSpace(AGameSpace* NewCoreSpace)
{
	CoreGameSpace = NewCoreSpace;
}

void AGameBoard::AddGameSpace(AGameSpace* NewCoreSpace)
{
	AllGameSpaces.Add(NewCoreSpace);
}
