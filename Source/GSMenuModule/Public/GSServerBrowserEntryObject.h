// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GSServerBrowserEntryStruct.h"
#include "UObject/NoExportTypes.h"
#include "GSServerBrowserEntryObject.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class GSMENUMODULE_API UGSServerBrowserEntryObject : public UObject
{
	GENERATED_BODY()
	public:
	UPROPERTY(EditAnywhere, Category="GS|Data")
	FGSServerBrowserEntryStruct EntryData;
};
