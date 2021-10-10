// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GSUserWidgetBase.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "GSServerBrowserEntryWidget.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class GSMENUMODULE_API UGSServerBrowserEntryWidget : public UGSUserWidgetBase, public IUserObjectListEntry
{
	GENERATED_BODY()
	
	protected:
	virtual void NativeOnListItemObjectSet(UObject* ListItemObject) override;
	
public:
	UPROPERTY(meta=(BindWidget))
	class UTextBlock* SessionNameTextField;
	
	UPROPERTY(meta=(BindWidget))
	class UTextBlock* SessionHostTextField;

	UPROPERTY(meta=(BindWidget))
	class UTextBlock* SessionPlayerCount;

};
