// Fill out your copyright notice in the Description page of Project Settings.
#if WITH_AUTOMATION_TESTS

#include "CTestTPS/Tests/SandboxTests.h"
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "CTestTPS/Tests/TestUtils.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMathMaxInt, "TPSGame.Math.MaxInt", 
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter | EAutomationTestFlags::HighPriority);

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMathSqrt, "TPSGame.Math.Sqrt",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter | EAutomationTestFlags::HighPriority);

using namespace TPSGame;

bool FMathMaxInt::RunTest(const FString& Paramenters)
{
	AddInfo("Max9int) func testing");

	typedef TArray<TestPayload<TInterval<int32>, int32>> MaxIntTestPayload;
	// clang-fromat off
	const MaxIntTestPayload TestData
	{
		{{13,25}, 25},
		{{25,25}, 25},
		{{0,25}, 25},
		{{0,0}, 0},
		{{-13,0}, 0},
		{{-13,-13}, -13},
		{{-13,-9}, -9}
	};
	// clang-fromat on

	for (const auto Data : TestData)
	{
		TestTrueExpr(FMath::Max(Data.TestValue.Min, Data.TestValue.Max) == Data.ExpectedValue);
	}

	return true;
}

bool FMathSqrt::RunTest(const FString& Paramenters)
{
	AddInfo("Sqrt function Testing");

	TestEqual("sqrt 4", FMath::Sqrt(4.0f), 2.0f);

	TestEqual("sqrt 3", FMath::Sqrt(3.0f), 1.7f, 0.1f);

	return true;
}

#endif