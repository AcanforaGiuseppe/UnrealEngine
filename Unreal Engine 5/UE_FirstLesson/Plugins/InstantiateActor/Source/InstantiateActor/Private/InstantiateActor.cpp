#include "Editor.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "InstantiateActor.h"

#define LOCTEXT_NAMESPACE "FInstantiateActorModule"

void FInstantiateActorModule::StartupModule()
{ }

void FInstantiateActorModule::ShutdownModule()
{ }

bool FInstantiateActorModule::Exec(UWorld* InWorld, const TCHAR* CMD, FOutputDevice& AR)
{
	int nTimesSpawn = 10;

	if (FParse::Command(&CMD, TEXT("InstantiateActor")))
	{
		TArray<FAssetData> AssetsData;
		GEditor->GetContentBrowserSelections(AssetsData);

		if (AssetsData.IsEmpty())
		{
			return false;
		}

		for (const FAssetData& AssetData : AssetsData)
		{
			UObject* Instance = AssetData.GetAsset();
			UClass* AssetClass = Instance->GetClass();

			if (!AssetClass->IsChildOf(UBlueprint::StaticClass()))
			{
				// Not an actor class
				continue;
			}

			AssetClass = Cast<UBlueprint>(Instance)->GeneratedClass;
			if (AssetClass->IsChildOf(AActor::StaticClass()))
			{
				// Actor class
				UWorld* World = GEditor->GetEditorWorldContext().World();
				if (World->WorldType == EWorldType::Editor)
				{
					for (int i = 0; i < nTimesSpawn; ++i)
					{
						World->SpawnActor<AActor>(AssetClass, FVector(0, 0, 100), FRotator());
					}
				}
			}
		}
		return true;
	}
	return false;
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FInstantiateActorModule, InstantiateActor)