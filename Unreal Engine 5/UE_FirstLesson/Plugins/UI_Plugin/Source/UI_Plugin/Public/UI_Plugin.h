#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FUI_PluginModule : public IModuleInterface
{
public:

	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	TSharedRef<SDockTab> SpawnNomadTab(const FSpawnTabArgs& TabSpawnArgs);
	void TextChanged(const FText& InText, ETextCommit::Type InCommitType);
	FReply ButtonClicked();
	FText ClassName;
	void ValueChanged(float Value);
};
