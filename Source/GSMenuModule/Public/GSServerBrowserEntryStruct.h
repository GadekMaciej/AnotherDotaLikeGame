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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GS")
	uint8 MaxNumberOfPlayers;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GS")
	uint8 CurrentNumberOfPlayers;

	FGSServerBrowserEntryStruct(
		FText NewSessionId = INVTEXT("NoId"),
		FText NewSessionName = INVTEXT("NoSessionName"),
		FText NewHostName = INVTEXT("noHostName"),
		uint8 NewMaxNumberOfPlayers = 2,
		uint8 NewCurrentNumberOfPlayers = 0
		) :
	SessionId(NewSessionId),
	SessionName(NewSessionName),
	HostName(NewHostName),
	MaxNumberOfPlayers(NewMaxNumberOfPlayers),
	CurrentNumberOfPlayers(NewCurrentNumberOfPlayers)
	{
		
	}
};