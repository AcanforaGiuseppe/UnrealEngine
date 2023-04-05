// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "StupidFunctionLibrary.generated.h"

UCLASS()
class TESTPLUGIN001_API UStupidFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AIV")
		static float GetGlobalSmartValue();
	UFUNCTION(BlueprintCallable, Category = "AIV")
		static int64 GetFactorial(const int64 Factor);
};