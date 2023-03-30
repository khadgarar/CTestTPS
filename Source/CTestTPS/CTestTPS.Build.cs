// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CTestTPS : ModuleRules
{
	public CTestTPS(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
		PublicIncludePaths.Add("CTestTPS");
	}
}
