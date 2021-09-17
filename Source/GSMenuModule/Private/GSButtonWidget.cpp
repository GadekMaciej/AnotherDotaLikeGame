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
	Super::SynchronizeProperties();
	// If edited inside Editor this widget won't override custom members
	if(!GetParent())
	{
		return;
	}
	if(TextBlockElement)
	{
		TextBlockElement->SetText(ButtonTextContent);
	}
}
