#include "UI_Plugin.h"
#include "Components/DirectionalLightComponent.h"
#include "Editor.h"
#include "EngineUtils.h"
#include "Framework/Docking/TabManager.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Input/SEditableTextBox.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Input/SSlider.h"

#define LOCTEXT_NAMESPACE "FUI_PluginModule"

static const FName DummyTab = TEXT("DummyTab");

extern "C"
{
	typedef const char* (*aiv_get_string_t)();
	typedef int (*aiv_adder_t)(const int a, const int b);
}

void FUI_PluginModule::StartupModule()
{
	UE_LOG(LogTemp, Warning, TEXT("Startup from Plugin001"));
	void* Handle = FPlatformProcess::GetDllHandle(TEXT("D:/libaiv.dll"));

	if (!Handle)
	{
		return;
	}

	aiv_get_string_t SymbolAddressGetString = reinterpret_cast<aiv_get_string_t>(FPlatformProcess::GetDllExport(Handle, TEXT("aiv_get_string")));

	if (!SymbolAddressGetString)
	{
		FPlatformProcess::FreeDllHandle(Handle);
		return;
	}

	aiv_adder_t SymbolAddressAdder = reinterpret_cast<aiv_adder_t>(FPlatformProcess::GetDllExport(Handle, TEXT("aiv_adder")));

	UE_LOG(LogTemp, Warning, TEXT("GetString and Adder: %s %d"), UTF8_TO_TCHAR(SymbolAddressGetString()), SymbolAddressAdder(10, 20));

	const TSharedRef<FGlobalTabmanager> TabManager = FGlobalTabmanager::Get();
	TabManager->RegisterNomadTabSpawner(DummyTab, FOnSpawnTab::CreateRaw(this, &FUI_PluginModule::SpawnNomadTab));
}

void FUI_PluginModule::ShutdownModule()
{
	const TSharedRef<FGlobalTabmanager> TabManager = FGlobalTabmanager::Get();
	TabManager->UnregisterNomadTabSpawner(DummyTab);
}

TSharedRef<SDockTab> FUI_PluginModule::SpawnNomadTab(const FSpawnTabArgs& TabSpawnArgs)
{
	return SNew(SDockTab).TabRole(ETabRole::NomadTab)
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot().AutoHeight()
		[
			SNew(SEditableTextBox).Text(FText::FromString("EditableTextBlock"))
			.OnTextCommitted_Raw(this, &FUI_PluginModule::TextChanged)
		]
	+ SVerticalBox::Slot().AutoHeight()
		[
			SNew(SButton).Text(FText::FromString("Button"))
			.OnClicked_Raw(this, &FUI_PluginModule::ButtonClicked)
		]
	+ SVerticalBox::Slot().AutoHeight()
		[
			SNew(SSlider).MinValue(0).MaxValue(10).OnValueChanged_Raw(this, &FUI_PluginModule::ValueChanged)
		]
		];
}

void FUI_PluginModule::TextChanged(const FText& InText, ETextCommit::Type InCommitType)
{
	ClassName = InText;
}

FReply FUI_PluginModule::ButtonClicked()
{
	UClass* FoundClass = FindObject<UClass>(ANY_PACKAGE, *ClassName.ToString());
	UWorld* World = GEditor->GetEditorWorldContext().World();
	World->SpawnActor(FoundClass);
	return FReply::Handled();
}

void FUI_PluginModule::ValueChanged(float Value)
{
	UWorld* World = GEditor->GetEditorWorldContext().World();

	for (TActorIterator<AActor> ItActor(World); ItActor; ++ItActor)
	{
		AActor* Actor = *ItActor;

		for (UActorComponent* Component : Actor->GetComponents())
		{
			UDirectionalLightComponent* LightComponent = Cast< UDirectionalLightComponent>(Component);

			if (LightComponent)
			{
				LightComponent->SetIntensity(Value);
			}
		}
	}
}
#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FUI_PluginModule, UI_Plugin)