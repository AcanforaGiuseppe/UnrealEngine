// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "StupidFactory.generated.h"

/**
 *
 */
UCLASS()
class TESTPLUGIN001_API UStupidFactory : public UFactory
{
	GENERATED_BODY()

public:
	UStupidFactory();

	UObject* FactoryCreateFile
	(
		UClass* InClass,
		UObject* InParent,
		FName InName,
		EObjectFlags Flags,
		const FString& Filename,
		const TCHAR* Parms,
		FFeedbackContext* Warn,
		bool& bOutOperationCanceled
	) override;
};
