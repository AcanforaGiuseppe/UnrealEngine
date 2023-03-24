// Fill out your copyright notice in the Description page of Project Settings.

#include "StupidFactory.h"
#include "ImageUtils.h"
#include "UselessObject.h"

UStupidFactory::UStupidFactory()
{
	bEditorImport = true;
	SupportedClass = UUselessObject::StaticClass();
	Formats.Add("foo;Foo Stupid Format");
}

UObject* UStupidFactory::FactoryCreateFile
(
	UClass* InClass,
	UObject* InParent,
	FName InName,
	EObjectFlags Flags,
	const FString& Filename,
	const TCHAR* Parms,
	FFeedbackContext* Warn,
	bool& bOutOperationCanceled
)
{
	UE_LOG(LogTemp, Error, TEXT("Filename %s"), *Filename);
	/*FCreateTexture2DParameters Params;
	TArray<FColor> Pixels;
	Pixels.AddZeroed(1024 * 1024);
	return FImageUtils::CreateTexture2D(1024, 1024, Pixels, InParent, InName.ToString(), Flags, Params);*/
	UUselessObject* Object = NewObject<UUselessObject>(InParent, InName, Flags);
	Object->DummyNumber = 123456789;
	return Object;
}