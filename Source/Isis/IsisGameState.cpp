// Fill out your copyright notice in the Description page of Project Settings.

#include "IsisGameState.h"

#include "GameBoard.h"
#include "GameBoardThreeByThree.h"

void AIsisGameState::SetCurrentGameBoard(AGameBoard * NewGameBoard)
{
	CurrentGameBoard = NewGameBoard;
}

void AIsisGameState::ResetGameState()
{
	UE_LOG(LogTemp, Warning, TEXT("Creating AIsisGameState"));
	//CurrentGameBoard = NewObject<AGameBoardThreeByThree>();
}

AGameBoard* AIsisGameState::GetCurrentGameBoard()
{
	return CurrentGameBoard;
}
