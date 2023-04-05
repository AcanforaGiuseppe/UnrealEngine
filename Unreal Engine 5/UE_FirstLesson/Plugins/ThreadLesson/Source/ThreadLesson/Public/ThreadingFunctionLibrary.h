#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ThreadingFunctionLibrary.generated.h"

DECLARE_DYNAMIC_DELEGATE_TwoParams(FAIVSlowResult, int64, Result, bool, bSuccess);

UCLASS()
class THREADLESSON_API UThreadingFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
		static void ComputeFactorial(const int64 Factor, const FAIVSlowResult& OnResult);
};