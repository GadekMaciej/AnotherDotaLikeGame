// Fill out your copyright notice in the Description page of Project Settings.


#include "GSUserWidgetBase.h"

void UGSUserWidgetBase::SynchronizeProperties()
{
	Super::SynchronizeProperties();
}

void UGSUserWidgetBase::NavigateToWidget(const TSubclassOf<UGSUserWidgetBase> NewWidget)
{
	
	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	UGSUserWidgetBase* CreatedWidget = CreateWidget<UGSUserWidgetBase>(PC, NewWidget);
	if(ensureAlwaysMsgf(CreatedWidget, TEXT("Could not create a widget to navigate to")))
	{
		SetVisibility(ESlateVisibility::Hidden);
		CreatedWidget->AddToViewport();
		RemoveFromViewport();
	}
}
