// Fill out your copyright notice in the Description page of Project Settings.


#include "Science/ScienceFuncLib.h"

DEFINE_LOG_CATEGORY_STATIC(LogFibinacci, All, All);

int32 UScienceFuncLib::Fibonacci(int32 Value)
{
	//check(Value >= 0);
	if (Value < 0)
	{
		UE_LOG(LogFibinacci, Error, TEXT("Invalid input for Fibonacci function: %i"), Value);
	}
	return Value <= 1 ? Value : Fibonacci(Value - 1) + Fibonacci(Value - 2);
}