// Copyright Epic Games, Inc. All Rights Reserved.

// First part
/*
#include "TestPlugin001.h"

#define LOCTEXT_NAMESPACE "FTestPlugin001Module"

//extern "C"
//{
typedef const char* (*aiv_get_string_t)();
typedef int (*aiv_adder_t)(const int a, const int b);
//}

DECLARE_DELEGATE(FAivSimpleDelegate);
DECLARE_MULTICAST_DELEGATE(FAivComplexDelegate);

struct FAivSomething
{
	FString Name;
	int32 Value;

	FAivSimpleDelegate SimpleDelegate;
	FAivComplexDelegate ComplexDelegate;

	void Hello()
	{ }
};

struct FBoh
{
	void HelloWorld()
	{ }
};

void Method(TSharedPtr<FAivSomething> SomethingPtr)
{
	// MANDATORY!
	// In UE, we'll have to put always the brackets "{ }" when coding
	if (SomethingPtr)
	{
		// Accessing a struct field:
		SomethingPtr->Hello();
	}
}

void Method(TSharedRef<FAivSomething> SomethingPtr)
{
	SomethingPtr->Hello();
}

void Method(TWeakPtr<FAivSomething> SomethingPtr)
{
	if (SomethingPtr.IsValid())
	{
		SomethingPtr.Pin()->Hello();

		// Execute / Execute if not associated to callbacks (Delegate)
		//SomethingPtr.Pin()->SimpleDelegate.Execute();
		SomethingPtr.Pin()->SimpleDelegate.ExecuteIfBound();

		// Multicast Delegate
		SomethingPtr.Pin()->ComplexDelegate.Broadcast();
	}
}

void Method(TUniquePtr<FAivSomething> SomethingPtr)
{
	SomethingPtr->Hello();
}

void FTestPlugin001Module::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	// With TSharedPtr
	{
		TSharedPtr<FAivSomething> SomethingPtr = MakeShared<FAivSomething>();

		TSharedRef<FBoh> Boh = MakeShared<FBoh>();
		SomethingPtr->SimpleDelegate.CreateSP(Boh, &FBoh::HelloWorld);

		// Delegate ->
		SomethingPtr->SimpleDelegate.CreateLambda([]()
			{
				UE_LOG(LogTemp, Error, TEXT("Blah Blah"));
			});
		// Overwriting the delegate
		SomethingPtr->SimpleDelegate.CreateLambda([]()
			{
				UE_LOG(LogTemp, Error, TEXT("Blah Blah"));
			});

		// Multicast Delegate ->
		SomethingPtr->ComplexDelegate.AddLambda([]()
			{
				UE_LOG(LogTemp, Error, TEXT("Blah Blah"));
			});
		SomethingPtr->ComplexDelegate.AddLambda([]()
			{
				UE_LOG(LogTemp, Error, TEXT("Blah Blah"));
			});
		SomethingPtr->ComplexDelegate.AddLambda([]()
			{
				UE_LOG(LogTemp, Error, TEXT("Blah Blah"));
			});

		// Will crash on nullptr
		//SomethingPtr = nullptr;
		Method(SomethingPtr);
		// Will crash if null
		Method(SomethingPtr.ToSharedRef());

		TWeakPtr<FAivSomething> IAmWeak = TWeakPtr<FAivSomething>(SomethingPtr);
	}

	// With TSharedRef
	{
		TSharedRef<FAivSomething> SomethingPtrRef = MakeShared<FAivSomething>();
		// Will crash if null
		Method(SomethingPtrRef);
	}

	AivHandle = FPlatformProcess::GetDllHandle(TEXT("D:/Development/- Projects/Unreal Engine/Unreal Engine 5/UE_FirstLesson/UnrealDll/libaiv.dll"));

	if (!AivHandle)
	{
		return;
	}

	aiv_get_string_t aiv_get_string = reinterpret_cast<aiv_get_string_t>(FPlatformProcess::GetDllExport(AivHandle, TEXT("aiv_get_string")));
	if (!aiv_get_string)
	{
		FPlatformProcess::FreeDllHandle(AivHandle);
		return;
	}

	aiv_adder_t aiv_adder = reinterpret_cast<aiv_adder_t>(FPlatformProcess::GetDllExport(AivHandle, TEXT("aiv_adder")));
	if (!aiv_adder)
	{
		FPlatformProcess::FreeDllHandle(AivHandle);
		return;
	}


	UE_LOG(LogTemp, Error, TEXT("Message from AIV: %s %d"), UTF8_TO_TCHAR(aiv_get_string()), aiv_adder(100, 200));

	TUniquePtr<FAivSomething> Only = MakeUnique<FAivSomething>();
	Method(MoveTemp(Only));

	TArray<FString> String;
	for (int32 i = 0; i < 1000000; i++)
	{
		String.Add("One");
	}

	TArray<TArray<FString>> Strings;
	Strings.Add(MoveTemp(String));

#pragma region FName

	// Fname 's -> light strings that share the same memory area
	FName Name001 = FName("Foo");

	// Comparing with FNAME_Find
	//FName Name001 = FName("Foo", FNAME_Find);

	FName Name002 = Name001;

	FText Message = LOCTEXT("Message", "I am a message");

#pragma endregion

	// Cultures
	TArray<FString> CultureNames;
	FInternationalization::Get().GetCultureNames(CultureNames);

	for (const FString& CultureName : CultureNames)
	{
		UE_LOG(LogTemp, Warning, TEXT("Culture: %s"), *CultureName);
	}
}

void FTestPlugin001Module::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	if (AivHandle)
	{
		FPlatformProcess::FreeDllHandle(AivHandle);
	}
}

FString FTestPlugin001Module::GetHelloWorld()
{
	return TEXT("Hello!!!!");
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FTestPlugin001Module, TestPlugin001)
*/

#include "TestPlugin001.h"
#include "UselessObject.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "Editor.h"

#define LOCTEXT_NAMESPACE "FTestPlugin001Module"


void FTestPlugin001Module::StartupModule()
{
	/*
	UUselessObject* UselessObject = NewObject<UUselessObject>();
	UE_LOG(LogTemp, Warning, TEXT("Useless: %s %s %s"), *UselessObject->GetName(), *UselessObject->GetPathName(), *UselessObject->GetFullName());

	UselessObject = NewObject<UUselessObject>();
	UE_LOG(LogTemp, Warning, TEXT("Useless: %s %s %s"), *UselessObject->GetName(), *UselessObject->GetPathName(), *UselessObject->GetFullName());

	UselessObject = NewObject<UUselessObject>();
	UE_LOG(LogTemp, Warning, TEXT("Useless: %s %s %s"), *UselessObject->GetName(), *UselessObject->GetPathName(), *UselessObject->GetFullName());

	UselessObject = NewObject<UUselessObject>();
	UE_LOG(LogTemp, Warning, TEXT("Useless: %s %s %s"), *UselessObject->GetName(), *UselessObject->GetPathName(), *UselessObject->GetFullName());

	UselessObject->DummyNumber = 100;

	UClass* UselessClass = UUselessObject::StaticClass();

	FProperty* DummyNumberProperty = UselessClass->FindPropertyByName(TEXT("DummyNumber"));

	UE_LOG(LogTemp, Error, TEXT("DummyNumberProperty at %p"), DummyNumberProperty);

	//FIntProperty* IntProperty = new FIntProperty(UselessClass, TEXT("DummyNumber"),
	//	RF_MarkAsNative | RF_Public | RF_Standalone | RF_Transient,
	//	STRUCT_OFFSET(UUselessObject, DummyNumber),
	//	CPF_Edit | CPF_BlueprintVisible);
	//
	//UselessClass->StaticLink(false);

	DummyNumberProperty = UselessClass->FindPropertyByName(TEXT("DummyNumber"));

	UE_LOG(LogTemp, Error, TEXT("DummyNumberProperty at %p"), DummyNumberProperty);

	UselessObject->AddToRoot();
	UselessObject->RemoveFromRoot();
	*/
}

bool FTestPlugin001Module::Exec(UWorld* World, const TCHAR* Cmd, FOutputDevice& Ar)
{
	if (FParse::Command(&Cmd, TEXT("aivprops")))
	{
		TArray<FAssetData> AssetsData;
		GEditor->GetContentBrowserSelections(AssetsData);
		for (const FAssetData& AssetData : AssetsData)
		{
			UObject* Instance = AssetData.GetAsset();
			UClass* AssetClass = Instance->GetClass();

			if (AssetClass->IsChildOf(UBlueprint::StaticClass()))
			{
				AssetClass = Cast<UBlueprint>(Instance)->GeneratedClass;
			}

			for (TFieldIterator<FProperty> It(AssetClass); It; ++It)
			{
				FProperty* Property = *It;

				if (FStrProperty* StrProperty = CastField<FStrProperty>(Property))
				{
					//const FString& String = StrProperty->GetPropertyValue_InContainer(Instance);
					//StrProperty->GetPropertyValue_InContainer(Instance);
					//UE_LOG(LogTemp, Warning, TEXT("Asset %s Prop %s Value %s"), *Instance->GetFullName(), *Property->GetName(), *String);
					UE_LOG(LogTemp, Warning, TEXT("Asset %s Prop %s"), *Instance->GetFullName(), *Property->GetName());
				}
			}
		}
	}

	if (FParse::Command(&Cmd, TEXT("aivworlds")))
	{
		for (TObjectIterator<UWorld> It; It; ++It)
		{
			UWorld* World = *It;
			UE_LOG(LogTemp, Warning, TEXT("Found World %s"), *World->GetFullName());
			if (World->WorldType == EWorldType::Editor)
			{
				UE_LOG(LogTemp, Error, TEXT("Hello I am the editor!"));
				AActor* Dummy = World->SpawnActor<AActor>(FVector(0, 0, 100), FRotator());
				//Dummy->Destroy();
				World->SpawnActor<AActor>(FVector(0, 0, 200), FRotator());
				World->SpawnActor<AActor>(FVector(0, 0, 300), FRotator());
			}
		}
	}

	if (FParse::Command(&Cmd, TEXT("aivassets")))
	{
		FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
		TArray<FAssetData> AssetsData;
		AssetRegistryModule.Get().GetAllAssets(AssetsData);

		for (const FAssetData& AssetData : AssetsData)
		{
			Ar.Logf(TEXT("Assets %s: %s"), *AssetData.GetFullName(), AssetData.IsAssetLoaded());
			//UUselessObject* Object = Cast<UUselessObject>(AssetData.GetAsset());
		}

		AssetsData.Empty();
		AssetRegistryModule.Get().GetAssetsByClass(*(UMaterial::StaticClass()->GetPathName()), AssetsData);
		for (const FAssetData& AssetData : AssetsData)
		{
			UE_LOG(LogTemp, Error, TEXT("Assets %s: %s"), *AssetData.GetFullName(), AssetData.IsAssetLoaded());
		}

		/*
		FARFilter Filter;
		Filter.bRecursivePaths = true;
		Filter.SoftObjectPaths.Add(FSoftObjectPath("/Game"));
		AssetsData.Empty();
		AssetRegistryModule.Get().GetAssets(Filter, AssetsData);
		for (const FAssetData& AssetData : AssetsData)
		{
			UE_LOG(LogTemp, Warning, TEXT("Assets %s: %s"), *AssetData.GetFullName(), AssetData.IsAssetLoaded());
		}
		*/
	}
	return false;
}

void FTestPlugin001Module::ShutdownModule()
{

}

FString FTestPlugin001Module::GetHelloWorld()
{
	return TEXT("Hello!!!");
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FTestPlugin001Module, TestPlugin001)