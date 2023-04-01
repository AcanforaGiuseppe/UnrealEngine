using UnrealBuildTool;
using System.Collections.Generic;

public class BombermanOnlineTarget : TargetRules
{
    public BombermanOnlineTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Game;
        DefaultBuildSettings = BuildSettingsVersion.V2;
        ExtraModuleNames.Add("BombermanOnline");
    }
}