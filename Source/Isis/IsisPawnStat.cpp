// Fill out your copyright notice in the Description page of Project Settings.

#include "IsisPawnStat.h"

EPawnStatType UIsisPawnStat::GetStatType() const
{
	return StatType;
}

int32 UIsisPawnStat::GetCurrentStatValue() const
{
	return CurrentStatValue;
}

void UIsisPawnStat::SetCurrentStatValue(int32 NewValue)
{
	CurrentStatValue = NewValue;
}

void UIsisPawnStat::SetStatType(EPawnStatType NewStatType)
{
	StatType = NewStatType;
}

void UIsisPawnStat::SetDefaultStat(int32 NewDefaultStatValue)
{
	DefaultStatValue = NewDefaultStatValue;
}

void UIsisPawnStat::ResetStat()
{
	CurrentStatValue = DefaultStatValue;
}