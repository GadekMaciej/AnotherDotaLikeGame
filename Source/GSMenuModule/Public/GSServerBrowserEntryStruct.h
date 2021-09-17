#pragma once
#include "GSServerBrowserEntryStruct.generated.h"
USTRUCT(BlueprintType )
struct FGSServerBrowserEntryStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GS")
	FText SessionName;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GS")
	FText HostName;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GS")
	FText SessionId;
};