// Copyright Epic Games, Inc. All Rights Reserved.

#include "ToolbarTest001Style.h"
#include "ToolbarTest001.h"
#include "Framework/Application/SlateApplication.h"
#include "Styling/SlateStyleRegistry.h"
#include "Slate/SlateGameResources.h"
#include "Interfaces/IPluginManager.h"
#include "Styling/SlateStyleMacros.h"

#define RootToContentDir Style->RootToContentDir

TSharedPtr<FSlateStyleSet> FToolbarTest001Style::StyleInstance = nullptr;

void FToolbarTest001Style::Initialize()
{
	if (!StyleInstance.IsValid())
	{
		StyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*StyleInstance);
	}
}

void FToolbarTest001Style::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*StyleInstance);
	ensure(StyleInstance.IsUnique());
	StyleInstance.Reset();
}

FName FToolbarTest001Style::GetStyleSetName()
{
	static FName StyleSetName(TEXT("ToolbarTest001Style"));
	return StyleSetName;
}


const FVector2D Icon16x16(16.0f, 16.0f);
const FVector2D Icon20x20(20.0f, 20.0f);

TSharedRef< FSlateStyleSet > FToolbarTest001Style::Create()
{
	TSharedRef< FSlateStyleSet > Style = MakeShareable(new FSlateStyleSet("ToolbarTest001Style"));
	Style->SetContentRoot(IPluginManager::Get().FindPlugin("ToolbarTest001")->GetBaseDir() / TEXT("Resources"));

	Style->Set("ToolbarTest001.PluginAction", new IMAGE_BRUSH_SVG(TEXT("PlaceholderButtonIcon"), Icon20x20));
	return Style;
}

void FToolbarTest001Style::ReloadTextures()
{
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
	}
}

const ISlateStyle& FToolbarTest001Style::Get()
{
	return *StyleInstance;
}
