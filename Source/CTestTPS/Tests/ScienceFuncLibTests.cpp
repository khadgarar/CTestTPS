// Fill out your copyright notice in the Description page of Project Settings.

#if WITH_AUTOMATION_TESTS

#include "Tests/ScienceFuncLibTests.h"
#include "CTestTPS/Tests/TestUtils.h"
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Science/ScienceFuncLib.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FFibonacciSimple, "TPSGame.Science.Fibonacci.Simple",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter | EAutomationTestFlags::CriticalPriority);

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FFibonacciStress, "TPSGame.Science.Fibonacci.Stress",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::StressFilter | EAutomationTestFlags::LowPriority);

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FFibonacciLogHasErrors, "TPSGame.Science.Fibonacci.FibonacciLogHasErrors",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter | EAutomationTestFlags::CriticalPriority);

using namespace TPSGame;

bool FFibonacciSimple::RunTest(const FString& Paramenters)
{
	AddInfo("Fibonacci simple Testing");

	const TArray<TestPayload<int32, int32>> TestData{ {0,0}, {1,1}, {2,1}, {3,2}, {4,3}, {5,5}};
	for (const auto Data : TestData)
	{
		//TestTrueExpr(UScienceFuncLib::Fibonacci(Data.TestValue) == Data.ExpectedValue);
		const FString InfoString = FString::Printf(TEXT("Test value: %i, expected value: %i"), Data.TestValue, Data.ExpectedValue);
		TestEqual(InfoString, UScienceFuncLib::Fibonacci(Data.TestValue), Data.ExpectedValue);
	}

	return true;
}

bool FFibonacciStress::RunTest(const FString& Paramenters)
{
	AddInfo("Fibonacci stress Testing");
	/*for (int32 i = 2; i < 40; ++i)
	{
		TestTrueExpr(UScienceFuncLib::Fibonacci(i) == 
			UScienceFuncLib::Fibonacci(i-1) + UScienceFuncLib::Fibonacci(i-2));
	}*/
	int32 PrevPrevValue = 0;
	int32 PrevValue = 1;
	for (int32 i = 2; i < 40; ++i)
	{
		const int32 CurrnetValue = UScienceFuncLib::Fibonacci(i);
		TestTrueExpr(CurrnetValue == PrevPrevValue + PrevValue);
		PrevPrevValue = PrevValue;
		PrevValue = CurrnetValue;
	}
	return true;
}

bool FFibonacciLogHasErrors::RunTest(const FString& Paramenters)
{
	AddInfo("Fibonacci num <0 produces error");
	AddExpectedError("Invalid input for Fibonacci", EAutomationExpectedErrorFlags::Contains);
	UScienceFuncLib::Fibonacci(-10);
	return true;
}
#endif