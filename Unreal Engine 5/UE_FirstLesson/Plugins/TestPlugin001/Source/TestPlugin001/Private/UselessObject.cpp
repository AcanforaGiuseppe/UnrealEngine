// Fill out your copyright notice in the Description page of Project Settings.

#include "UselessObject.h"

UUselessObject::UUselessObject()
{
	UE_LOG(LogTemp, Error, TEXT("Hello I am UselessObject at %p"), this);
}

UUselessObject::~UUselessObject()
{
	UE_LOG(LogTemp, Error, TEXT("Goodbye I am UselessObject at %p"), this);
}

int32 UUselessObject::GetNumber(const FString& Value)
{
	return Value.Len();
}

void UUselessObject::Serialize(FArchive& Ar)
{
	Super::Serialize(Ar);
	int32 DummyValue = 100;
	Ar << DummyValue;
}