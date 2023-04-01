// Copyright Epic Games, Inc. All Rights Reserved.

#include "SlateTest.h"
#include "Framework/Docking/TabManager.h"
#include "WorkspaceMenuStructureModule.h"
#include "Widgets/Input/SEditableTextBox.h"
#include "Widgets/Input/SSlider.h"
#include "WorkspaceMenuStructure.h"

#define LOCTEXT_NAMESPACE "FSlateTestModule"

static const FName DummyDockTab("SlateTest");

void FSlateTestModule::StartupModule()
{
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(DummyDockTab, FOnSpawnTab::CreateRaw(this, &FSlateTestModule::CreateSlateTab))
		.SetGroup(WorkspaceMenu::GetMenuStructure().GetDeveloperToolsMiscCategory());
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FSlateTestModule::ShutdownModule()
{
	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(DummyDockTab);
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

TSharedRef<SDockTab> FSlateTestModule::CreateSlateTab(const FSpawnTabArgs& TabArgs)
{
	return SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
		[
			SNew(SVerticalBox)
			+SVerticalBox::Slot().AutoHeight()
			[
				//SNew(STextBlock).Text(FText::FromString("Hello world"))
				//SNew(STextBlock).Text_Raw(this, &FSlateTestModule::GetSlateText)
				SNew(STextBlock).Text_Lambda([]() -> FText
					{
						return FText::FromString(FString::Printf(TEXT("Current time %f"), (FPlatformTime::Seconds())));
					})
			]
			+SVerticalBox::Slot().AutoHeight()
			[
				SAssignNew(TextBlock,STextBlock).Text_Raw(this, &FSlateTestModule::GetSlateText)
			]
			+SVerticalBox::Slot().AutoHeight()
			[
				SNew(SSlider).MinValue(10).MaxValue(200).OnValueChanged_Lambda([this](float value)
					{
						//UE_LOG(LogTemp, Warning, TEXT("%f"), value);
						TextBlock->SetText(FText::FromString(FString::Printf(TEXT("Slider value %f"), value)));
					})
			]
			+ SVerticalBox::Slot().AutoHeight()
				[
					SNew(SColorBlock).Color(FLinearColor::Blue)

				]
		];
}

FText FSlateTestModule::GetSlateText() const
{
	return FText::FromString(FString::Printf(TEXT("Current time %f"), (FPlatformTime::Seconds())));
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FSlateTestModule, SlateTest)