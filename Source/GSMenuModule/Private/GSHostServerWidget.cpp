// Fill out your copyright notice in the Description page of Project Settings.


#include "GSHostServerWidget.h"

#include "GSButtonWidget.h"
#include "Components/Button.h"

void UGSHostServerWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	BackButton->ButtonElement->OnClicked.AddDynamic(this, &UGSHostServerWidget::OnBackButtonClicked);
	HostButton->ButtonElement->OnClicked.AddDynamic(this, &UGSHostServerWidget::OnHostButtonClicked);
}

void UGSHostServerWidget::OnBackButtonClicked()
{
	NavigateToWidget(ServerBrowserClass);
}

void UGSHostServerWidget::OnHostButtonClicked()
{
}
