// Fill out your copyright notice in the Description page of Project Settings.


#include "GSHostServerWidget.h"

#include "GSButtonWidget.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "OnlineSubsystem.h"

void UGSHostServerWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	BackButton->ButtonElement->OnClicked.AddDynamic(this, &UGSHostServerWidget::OnBackButtonClicked);
	HostButton->ButtonElement->OnClicked.AddDynamic(this, &UGSHostServerWidget::OnHostButtonClicked);
}

void UGSHostServerWidget::OnBackButtonClicked()
{
	if(!FOnBackButtonClickedEvent.ExecuteIfBound())
	{
		checkNoEntry();
	}
}

void UGSHostServerWidget::OnHostButtonClicked()
{
	if(!FOnHostButtonClickedEvent.ExecuteIfBound())
	{
		checkNoEntry();
	}
}
