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
	NavigateToWidget(ServerBrowserClass);
}

void UGSHostServerWidget::OnHostButtonClicked()
{
	const FName SessionName = FName(ServerNameEditText->GetText().ToString());

	// sandbox \/
	//FOnlineSessionSettings ExampleSessionSettings;
	//IOnlineSession::CreateSession(0, SessionName, ExampleSessionSettings);
	//IOnlineSession::OnCreateSessionCompleteDelegates.AddUObject(this, &UGSHostServerWidget::OnSessionCreated);
	// end ^^^
}

void UGSHostServerWidget::OnSessionCreated(FName SessionName, bool bWasSuccessful)
{
	IOnlineSubsystem::Get();
}
