// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE_FirstLesson.h"
#include "Modules/ModuleManager.h"
#include "Misc/FileHelper.h"
#include "Dummy003.h"
#include "TestPlugin001.h"

DEFINE_LOG_CATEGORY(LogAIV);

bool operator<(const FModuleStatus& ModuleA, const FModuleStatus& ModuleB)
{
	return ModuleA.Name < ModuleB.Name;
}

class FAivGameModule : public FDefaultGameModuleImpl, public FSelfRegisteringExec
{
public:
	virtual void StartupModule() override
	{
		//UE_LOG(LogAIV, /*Error*/ Fatal, TEXT("Hello AIV!"));

		FTestPlugin001Module& Module001 = FModuleManager::LoadModuleChecked<FTestPlugin001Module>("TestPlugin001");
		Module001.GetHelloWorld();

		FDummy003Module::HelloWorld();

		/*FString Message = TEXT("Hello?Test?");

		FFileHelper::SaveStringToFile(Message, TEXT("Z:/simplestring.txt"));*/

		/*

		TArray<FModuleStatus> ModuleStatuses;
		FModuleManager::Get().QueryModules(ModuleStatuses);

		ModuleStatuses.Sort();

		TArray<int32, TFixedAllocator<5>> Array;
		TArray<int32, TInlineAllocator<5>> ArrayWithMalloc;
		// Crashing:
		Array.Add(1);
		Array.Add(1);
		Array.Add(1);
		Array.Add(1);
		Array.Add(1);
		Array.Add(1);
		// Not Crashing:
		ArrayWithMalloc.Add(1);
		ArrayWithMalloc.Add(1);
		ArrayWithMalloc.Add(1);
		ArrayWithMalloc.Add(1);
		ArrayWithMalloc.Add(1);
		ArrayWithMalloc.Add(1);

		//for(int32 Index = 0; Index < ModuleStatuses.Num(); Index++)
		for (const FModuleStatus& ModuleStatus : ModuleStatuses)
		{
			UE_LOG(LogTemp, Error, TEXT("Module: %s %s"), *ModuleStatus.FilePath, *ModuleStatus.Name);
		}
		UE_LOG(LogTemp, Warning, TEXT("Hello world from AIV Module"));

		FString Hello = TEXT("hello");

		// OK
		FString Hello1 = UTF8_TO_TCHAR("hello");
		// NOT OK
		TCHAR* Hello2 = UTF8_TO_TCHAR("hello");

		Hello[2] = 'x';

		Hello.Equals("Hello"); // false

		//FModuleStatus* ModuleStatuses2 = ModuleStatuses.GetData();

		*/
	}

	virtual void ShutdownModule() override
	{
		UE_LOG(LogTemp, Warning, TEXT("Goodbye world from AIV Module"));
	}

	virtual bool SupportsDynamicReloading() override
	{
		return false;
	}

	virtual bool Exec(UWorld* World, const TCHAR* Cmd, FOutputDevice& Ar)
	{
		if (FParse::Command(&Cmd, TEXT("foobar")))
		{
			TArray<FModuleStatus> ModuleStatuses;
			FModuleManager::Get().QueryModules(ModuleStatuses);

			ModuleStatuses.Sort();

			for (const FModuleStatus& ModuleStatus : ModuleStatuses)
				if (ModuleStatus.Name.StartsWith(Cmd))
					Ar.Logf(TEXT("Module: %s %s"), *ModuleStatus.FilePath, *ModuleStatus.Name);

			return true;
		}
		return false;
	}
};

IMPLEMENT_PRIMARY_GAME_MODULE(FAivGameModule, UE_FirstLesson, "UE_FirstLesson");