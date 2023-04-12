#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FInstantiateActorModule : public IModuleInterface, public FSelfRegisteringExec
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	
	virtual bool Exec(UWorld* InWorld, const TCHAR* CMD, FOutputDevice& AR) override;
};