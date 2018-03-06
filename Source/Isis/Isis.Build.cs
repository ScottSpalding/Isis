// Fill out your copyright notice in the Description page of Project Settings.

using System.IO;
using System.Collections.Generic;
using Tools.DotNETCommon;
using UnrealBuildTool;

public class Isis : ModuleRules
{
	public Isis(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "GameplayTags", "InputCore" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

        // Load SkookumScript.ini and add any ScriptSupportedModules specified to the list of PrivateDependencyModuleNames
        PrivateDependencyModuleNames.AddRange(GetSkookumScriptModuleNames(Path.Combine(ModuleDirectory, "../..")));

        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
    }

    // Load SkookumScript.ini and return any ScriptSupportedModules specified
    public static List<string> GetSkookumScriptModuleNames(string PluginOrProjectRootDirectory, bool AddSkookumScriptRuntime = true)
    {
        List<string> moduleList = null;

        // Load SkookumScript.ini and get ScriptSupportedModules
        string iniFilePath = Path.Combine(PluginOrProjectRootDirectory, "Config/SkookumScript.ini");
        if (File.Exists(iniFilePath))
        {
            ConfigFile iniFile = new ConfigFile(new FileReference(iniFilePath), ConfigLineAction.Add);
            var skookumConfig = new ConfigHierarchy(new ConfigFile[] { iniFile });
            skookumConfig.GetArray("CommonSettings", "ScriptSupportedModules", out moduleList);
        }

        if (moduleList == null)
        {
            moduleList = new List<string>();
        }

        // Add additional modules needed for SkookumScript to function
        moduleList.Add("AgogCore");
        moduleList.Add("SkookumScript");
        if (AddSkookumScriptRuntime)
        {
            moduleList.Add("SkookumScriptRuntime");
        }

        return moduleList;
    }
}
