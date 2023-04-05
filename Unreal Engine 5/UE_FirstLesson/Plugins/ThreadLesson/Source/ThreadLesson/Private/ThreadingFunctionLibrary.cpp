#include "ThreadingFunctionLibrary.h"

void UThreadingFunctionLibrary::ComputeFactorial(const int64 Factor, const FAIVSlowResult& OnResult)
{
	if (Factor < 0)
	{
		OnResult.ExecuteIfBound(0, false);
		return;
	}

	if (Factor == 0 || Factor == 1)
	{
		OnResult.ExecuteIfBound(1, true);
		return;
	}

	Async(EAsyncExecution::Thread, [Factor, OnResult]()
		{
			int64 Value = 1;
			for (int64 Index = 1; Index <= Factor; Index++)
			{
				Value *= Index;
			}

			UE_LOG(LogTemp, Error, TEXT("Factor: %lld Value: %lld"), Factor, Value);

			FFunctionGraphTask::CreateAndDispatchWhenReady([Value, OnResult]()
				{
					OnResult.ExecuteIfBound(Value, true);
				});
		});
}