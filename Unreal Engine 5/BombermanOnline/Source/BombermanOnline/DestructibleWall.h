#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "DestructibleWall.generated.h"

UCLASS()
class BOMBERMANONLINE_API ADestructibleWall : public AStaticMeshActor
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
		void DestroyWall();
};