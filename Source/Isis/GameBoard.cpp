// Fill out your copyright notice in the Description page of Project Settings.

#include "GameBoard.h"




UGameSpace* UGameBoard::GetCoreGameSpace()
{
	return CoreGameSpace;
}

void UGameBoard::SetCoreGameSpace(UGameSpace * GameSpace)
{
	CoreGameSpace = GameSpace;
}
