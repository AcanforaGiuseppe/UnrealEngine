// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "ToolbarTest001Style.h"

class FToolbarTest001Commands : public TCommands<FToolbarTest001Commands>
{
public:

	FToolbarTest001Commands()
		: TCommands<FToolbarTest001Commands>(TEXT("ToolbarTest001"), NSLOCTEXT("Contexts", "ToolbarTest001", "ToolbarTest001 Plugin"), NAME_None, FToolbarTest001Style::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > PluginAction;
};
