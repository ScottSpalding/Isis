// Fill out your copyright notice in the Description page of Project Settings.

#include "IsisPawnStats.h"


// Sets default values for this component's properties
UIsisPawnStats::UIsisPawnStats()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UIsisPawnStats::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UIsisPawnStats::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

int32 UIsisPawnStats::GetStatCurrentValue(EPawnStatType PawnStatType) const
{
	for (UIsisPawnStat* CurrentStat : CurrentStats)
	{
		if (CurrentStat->GetStatType() == PawnStatType)
		{
			return CurrentStat->GetCurrentStatValue();
		}
	}
	// TODO We need a stat, so getting here is super bad, but return Int32 will  have terrible results.
	return INT32_MAX;
}

void UIsisPawnStats::SetCurrentStat(EPawnStatType PawnStatType, int32 NewStatValue)
{
	/*UIsisPawnStat* NewStat = NewObject<UIsisPawnStat>();
	NewStat->SetStatType(PawnStatType);
	NewStat->SetDefaultStat(NewStatValue);
	CurrentStats.Add(NewStat);*/
	for (UIsisPawnStat* CurrentStat : CurrentStats)
	{
		if (CurrentStat->GetStatType() == PawnStatType)
		{
			CurrentStat->SetCurrentStatValue(NewStatValue);
		}
	}
}

void UIsisPawnStats::SetDefaultStat(EPawnStatType PawnStatType, int32 NewStatValue)
{
	/*auto OldStatPointer = CurrentStats.FindByPredicate([PawnStatType](const UIsisPawnStat& StatToCheck)
	{
	return StatToCheck.StatType == PawnStatType;
	});
	if (OldStatPointer)
	{
	}*/

	// TODO make better
	int32 FoundIndex = -1;
	for (int32 Index = 0; Index < CurrentStats.Num(); Index++)
	{
		if (CurrentStats[Index]->GetStatType() == PawnStatType)
		{
			UE_LOG(LogTemp, Warning, TEXT("Removing existing IsisPawnStat."));
			FoundIndex = Index;
			break;
		}
	}
	if (FoundIndex != -1)
	{
		CurrentStats.RemoveAt(FoundIndex);
	}

	UIsisPawnStat* NewStat = NewObject<UIsisPawnStat>();
	NewStat->SetStatType(PawnStatType);
	NewStat->SetDefaultStat(NewStatValue);
	CurrentStats.Add(NewStat);
	UE_LOG(LogTemp, Warning, TEXT("Added new IsisPawnStat {%s}.  Count is: {%i}"), *NewStat->GetName(), CurrentStats.Num());
}

void UIsisPawnStats::ResetStats()
{
	for (UIsisPawnStat* CurrentStat : CurrentStats)
	{
		CurrentStat->ResetStat();
	}
}