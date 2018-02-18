// Fill out your copyright notice in the Description page of Project Settings.

#include "GameBoardThreeByThree.h"

#include "GameSpace.h"

UGameBoardThreeByThree::UGameBoardThreeByThree()
{
	UE_LOG(LogTemp, Warning, TEXT("Creating UGameBoardThreeByThree"));

	Height = 3;
	Width = 3;

	UGameSpace* NewCoreSpace = NewObject<UGameSpace>();

	UGameSpace* Left = NewObject<UGameSpace>();
	UGameSpace* Right = NewObject<UGameSpace>();
	UGameSpace* Up = NewObject<UGameSpace>();
	UGameSpace* Down = NewObject<UGameSpace>();

	NewCoreSpace->AddAdjacentGameSpace(Left);
	NewCoreSpace->AddAdjacentGameSpace(Right);
	NewCoreSpace->AddAdjacentGameSpace(Up);
	NewCoreSpace->AddAdjacentGameSpace(Down);

	UGameSpace* LeftUpCorner = NewObject<UGameSpace>();
	UGameSpace* RightUpCorner = NewObject<UGameSpace>();
	UGameSpace* LeftDownCorner = NewObject<UGameSpace>();
	UGameSpace* RightDownCorner = NewObject<UGameSpace>();

	Left->AddAdjacentGameSpace(NewCoreSpace);
	Left->AddAdjacentGameSpace(LeftUpCorner);
	Left->AddAdjacentGameSpace(LeftDownCorner);

	Right->AddAdjacentGameSpace(NewCoreSpace);
	Right->AddAdjacentGameSpace(RightUpCorner);
	Right->AddAdjacentGameSpace(RightDownCorner);

	Up->AddAdjacentGameSpace(NewCoreSpace);
	Up->AddAdjacentGameSpace(RightUpCorner);
	Up->AddAdjacentGameSpace(LeftUpCorner);

	Down->AddAdjacentGameSpace(NewCoreSpace);
	Down->AddAdjacentGameSpace(LeftDownCorner);
	Down->AddAdjacentGameSpace(RightDownCorner);

	LeftUpCorner->AddAdjacentGameSpace(Left);
	LeftUpCorner->AddAdjacentGameSpace(Up);

	RightUpCorner->AddAdjacentGameSpace(Right);
	RightUpCorner->AddAdjacentGameSpace(Up);

	LeftDownCorner->AddAdjacentGameSpace(Left);
	LeftDownCorner->AddAdjacentGameSpace(Down);

	RightDownCorner->AddAdjacentGameSpace(Right);
	RightDownCorner->AddAdjacentGameSpace(Down);

	SetCoreGameSpace(NewCoreSpace);

	AllGameSpaces.Add(NewCoreSpace);
	AllGameSpaces.Add(Left);
	AllGameSpaces.Add(Right);
	AllGameSpaces.Add(Up);
	AllGameSpaces.Add(Down);
	AllGameSpaces.Add(LeftUpCorner);
	AllGameSpaces.Add(RightUpCorner);
	AllGameSpaces.Add(LeftDownCorner);
	AllGameSpaces.Add(RightDownCorner);

	UE_LOG(LogTemp, Warning, TEXT("Constructed UGameBoardThreeByThree"));
}

int32 UGameBoardThreeByThree::GetHeight()
{
	return Height;
}

int32 UGameBoardThreeByThree::GetWidth()
{
	return Width;
}
