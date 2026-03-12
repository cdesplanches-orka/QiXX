// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class QiXX : ModuleRules
{
	public QiXX(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"NavigationSystem",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"Niagara",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"QiXX",
			"QiXX/Isometric",
			"QiXX/Variant_Strategy",
			"QiXX/Variant_Strategy/UI",
			"QiXX/Variant_TwinStick",
			"QiXX/Variant_TwinStick/AI",
			"QiXX/Variant_TwinStick/Gameplay",
			"QiXX/Variant_TwinStick/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
