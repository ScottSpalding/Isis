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

//TArray<FInnerArray> AGameBoard::GetGameBoardArray() const
//{
//	return TArray<FInnerArray>();
//}

void AGameBoard::SetCoreGameSpace(AGameSpace* NewCoreSpace)
{
	CoreGameSpace = NewCoreSpace;
}

void AGameBoard::AddGameSpace(AGameSpace * NewCoreSpace)
{
	AllGameSpaces.Add(NewCoreSpace);
}
