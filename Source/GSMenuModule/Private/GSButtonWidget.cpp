// Fill out your copyright notice in the Description page of Project Settings.


#include "GSButtonWidget.h"

#include "Components/TextBlock.h"

void UGSButtonWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UGSButtonWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void UGSButtonWidget::SynchronizeProperties()
{
	// If edited inside Editor this widget won't override custom members
	if(!GetParent())
	{
		return;
	}
	Super::SynchronizeProperties();
	if(TextBlockElement)
	{
		TextBlockElement->SetText(ButtonTextContent);
	}
}
