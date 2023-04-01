using UnrealBuildTool;
using System.Collections.Generic;

public class BombermanOnlineEditorTarget : TargetRules
{
    public BombermanOnlineEditorTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Editor;
        DefaultBuildSettings = BuildSettingsVersion.V2;
        ExtraModuleNames.Add("BombermanOnline");
    }
}