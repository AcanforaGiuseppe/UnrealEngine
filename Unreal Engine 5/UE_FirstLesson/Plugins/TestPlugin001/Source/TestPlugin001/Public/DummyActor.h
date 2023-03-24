// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DummyActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FStupidDelegate, float, Value);

UCLASS()
class TESTPLUGIN001_API ADummyActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADummyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString WeirdName;

	UFUNCTION(BlueprintCallable, BlueprintPure)
		float GetSmartFloat() const;

	UFUNCTION(BlueprintCallable)
		float GetStupidFloat();

	UPROPERTY(BlueprintAssignable, Category = "AIV")
		FStupidDelegate StupidEvent;

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		float ImplementMePlease(const FString& Value);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		float ImplementMeAgainPlease(const FString& Value);
};