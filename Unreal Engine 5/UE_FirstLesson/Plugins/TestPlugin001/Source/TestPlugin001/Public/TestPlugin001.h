// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

// Registering to GC Collector thanks to <FGCObject>
struct FHello /*: public FGCObject*/
{
	int32 Test;
};

class TESTPLUGIN001_API FTestPlugin001Module : public IModuleInterface, public FSelfRegisteringExec
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	bool Exec(UWorld* World, const TCHAR* Cmd, FOutputDevice& Ar) override;

	FString GetHelloWorld();

protected:
	void* AivHandle = nullptr;
	//TStrongObjectPtr<FHello> HelloPtr;
	//TWeakPtr<FAivSomething> SomethingPtr;
};