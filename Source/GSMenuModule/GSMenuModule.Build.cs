// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GSMenuModule : ModuleRules
{
	public GSMenuModule(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[]
		{
			"OnlineSubsystem",
			"OnlineSubsystemUtils",
			"GSOnlineSubSystemModule"
		});

		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"Core", 
			"CoreUObject",
			"UMG"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
