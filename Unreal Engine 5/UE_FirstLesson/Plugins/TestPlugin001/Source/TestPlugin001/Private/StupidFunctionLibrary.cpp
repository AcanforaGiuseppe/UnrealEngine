// Fill out your copyright notice in the Description page of Project Settings.

#include "StupidFunctionLibrary.h"

float UStupidFunctionLibrary::GetGlobalSmartValue()
{
	return 678;
}

int64 UStupidFunctionLibrary::GetFactorial(const int64 Factor)
{
	int64 Value = 1;

	for (int64 i = 1; i <= Factor; i++)
	{
		Value *= i;
	}

	return Value;
}