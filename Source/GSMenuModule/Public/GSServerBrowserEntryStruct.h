#pragma once
#include "GSServerBrowserEntryStruct.generated.h"
USTRUCT(BlueprintType )
struct FGSServerBrowserEntryStruct
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GS")
	FText SessionId;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GS")
	FText SessionName;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GS")
	FText HostName;

	FGSServerBrowserEntryStruct(
		FText NewSessionId = INVTEXT("NoId"),
		FText NewSessionName = INVTEXT("NoSessionName"),
		FText NewHostName = INVTEXT("noHostName")
		) :
	SessionId(NewSessionId),
	SessionName(NewSessionName),
	HostName(NewHostName)
	{
		
	}
};