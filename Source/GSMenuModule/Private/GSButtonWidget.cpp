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
	if(TextBlock)
	{
		TextBlock->SetText(ButtonTextContent);
	}
}
