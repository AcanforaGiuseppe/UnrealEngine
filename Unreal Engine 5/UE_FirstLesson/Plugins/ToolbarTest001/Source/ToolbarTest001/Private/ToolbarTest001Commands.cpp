// Copyright Epic Games, Inc. All Rights Reserved.

#include "ToolbarTest001Commands.h"

#define LOCTEXT_NAMESPACE "FToolbarTest001Module"

void FToolbarTest001Commands::RegisterCommands()
{
	UI_COMMAND(PluginAction, "ToolbarTest001", "Execute ToolbarTest001 action", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
