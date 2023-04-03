// Copyright Epic Games, Inc. All Rights Reserved.

#include "ToolbarTest001.h"
#include "ToolbarTest001Style.h"
#include "ToolbarTest001Commands.h"
#include "Misc/MessageDialog.h"
#include "ToolMenus.h"

static const FName ToolbarTest001TabName("ToolbarTest001");

#define LOCTEXT_NAMESPACE "FToolbarTest001Module"

void FToolbarTest001Module::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FToolbarTest001Style::Initialize();
	FToolbarTest001Style::ReloadTextures();

	FToolbarTest001Commands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FToolbarTest001Commands::Get().PluginAction,
		FExecuteAction::CreateRaw(this, &FToolbarTest001Module::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FToolbarTest001Module::RegisterMenus));
}

void FToolbarTest001Module::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FToolbarTest001Style::Shutdown();

	FToolbarTest001Commands::Unregister();
}

void FToolbarTest001Module::PluginButtonClicked()
{
	// Put your "OnButtonClicked" stuff here
	FText DialogText = FText::Format(
							LOCTEXT("PluginButtonDialogText", "Add code to {0} in {1} to override this button's actions"),
							FText::FromString(TEXT("FToolbarTest001Module::PluginButtonClicked()")),
							FText::FromString(TEXT("ToolbarTest001.cpp"))
					   );
	FMessageDialog::Open(EAppMsgType::Ok, DialogText);
}

void FToolbarTest001Module::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FToolbarTest001Commands::Get().PluginAction, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar.PlayToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("PluginTools");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FToolbarTest001Commands::Get().PluginAction));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FToolbarTest001Module, ToolbarTest001)