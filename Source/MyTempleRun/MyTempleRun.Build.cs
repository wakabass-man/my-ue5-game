// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MyTempleRun : ModuleRules
{
	public MyTempleRun(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", 
			"GameplayAbilities", "GameplayTags", "GameplayTasks" });
	}
}
