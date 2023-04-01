// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Colors/SColorBlock.h"

#include "Modules/ModuleManager.h"

class FSlateTestModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	TSharedRef<SDockTab> CreateSlateTab(const FSpawnTabArgs& TabArgs);

	FText GetSlateText()const;

	TSharedPtr<STextBlock> TextBlock;
};
