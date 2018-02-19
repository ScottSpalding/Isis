// Fill out your copyright notice in the Description page of Project Settings.

#include "GameBoardThreeByThree.h"

#include "GameSpace.h"

AGameBoardThreeByThree::AGameBoardThreeByThree()
{
	//UE_LOG(LogTemp, Warning, TEXT("Creating AGameBoardThreeByThree"));

	//Height = 3;
	//Width = 3;

	//////auto LeftColumn = FInnerArray();
	////LeftColumn.GameSpaces.Init(nullptr, 3);
	//////auto CenterColumn = FInnerArray();
	////CenterColumn.GameSpaces.Init(nullptr, 3);
	//////auto RightColumn = FInnerArray();
	////RightColumn.GameSpaces.Init(nullptr, 3);
	////GameBoard.Add(LeftColumn);
	////GameBoard.Add(CenterColumn);
	////GameBoard.Add(RightColumn);

	//AGameSpace* NewCoreSpace = NewObject<AGameSpace>();
	//
	////GameBoard[1].GameSpaces[1] = NewCoreSpace;

	//AGameSpace* Left = NewObject<AGameSpace>(this, "Left");
	//AGameSpace* Right = NewObject<AGameSpace>(this, "Right");
	//AGameSpace* Up = NewObject<AGameSpace>(this, "Up");
	//AGameSpace* Down = NewObject<AGameSpace>(this, "Down");

	///*GameBoard[0].GameSpaces[1] = Left;
	//GameBoard[2].GameSpaces[1] = Right;
	//GameBoard[1].GameSpaces[0] = Up;
	//GameBoard[1].GameSpaces[2] = Down;*/

	//NewCoreSpace->AddAdjacentGameSpace(Left);
	//NewCoreSpace->AddAdjacentGameSpace(Right);
	//NewCoreSpace->AddAdjacentGameSpace(Up);
	//NewCoreSpace->AddAdjacentGameSpace(Down);

	//AGameSpace* LeftUpCorner = NewObject<AGameSpace>(this, "LeftUpCorner");
	//AGameSpace* RightUpCorner = NewObject<AGameSpace>(this, "RightUpCorner");
	//AGameSpace* LeftDownCorner = NewObject<AGameSpace>(this, "LeftDownCorner");
	//AGameSpace* RightDownCorner = NewObject<AGameSpace>(this, "RightDownCorner");

	///*GameBoard[0].GameSpaces[0] = LeftUpCorner;
	//GameBoard[2].GameSpaces[0] = RightUpCorner;
	//GameBoard[0].GameSpaces[2] = LeftDownCorner;
	//GameBoard[2].GameSpaces[2] = RightDownCorner;*/

	//Left->AddAdjacentGameSpace(NewCoreSpace);
	//Left->AddAdjacentGameSpace(LeftUpCorner);
	//Left->AddAdjacentGameSpace(LeftDownCorner);

	//Right->AddAdjacentGameSpace(NewCoreSpace);
	//Right->AddAdjacentGameSpace(RightUpCorner);
	//Right->AddAdjacentGameSpace(RightDownCorner);

	//Up->AddAdjacentGameSpace(NewCoreSpace);
	//Up->AddAdjacentGameSpace(RightUpCorner);
	//Up->AddAdjacentGameSpace(LeftUpCorner);

	//Down->AddAdjacentGameSpace(NewCoreSpace);
	//Down->AddAdjacentGameSpace(LeftDownCorner);
	//Down->AddAdjacentGameSpace(RightDownCorner);

	//LeftUpCorner->AddAdjacentGameSpace(Left);
	//LeftUpCorner->AddAdjacentGameSpace(Up);

	//RightUpCorner->AddAdjacentGameSpace(Right);
	//RightUpCorner->AddAdjacentGameSpace(Up);

	//LeftDownCorner->AddAdjacentGameSpace(Left);
	//LeftDownCorner->AddAdjacentGameSpace(Down);

	//RightDownCorner->AddAdjacentGameSpace(Right);
	//RightDownCorner->AddAdjacentGameSpace(Down);

	//SetCoreGameSpace(NewCoreSpace);

	//AllGameSpaces.Add(NewCoreSpace);
	//AllGameSpaces.Add(Left);
	//AllGameSpaces.Add(Right);
	//AllGameSpaces.Add(Up);
	//AllGameSpaces.Add(Down);
	//AllGameSpaces.Add(LeftUpCorner);
	//AllGameSpaces.Add(RightUpCorner);
	//AllGameSpaces.Add(LeftDownCorner);
	//AllGameSpaces.Add(RightDownCorner);

	//UE_LOG(LogTemp, Warning, TEXT("Constructed AGameBoardThreeByThree"));
}

int32 AGameBoardThreeByThree::GetHeight()
{
	return Height;
}

int32 AGameBoardThreeByThree::GetWidth()
{
	return Width;
}

//TArray<FInnerArray> AGameBoardThreeByThree::GetGameBoardArray() const
//{
//	return GameBoard;
//}
