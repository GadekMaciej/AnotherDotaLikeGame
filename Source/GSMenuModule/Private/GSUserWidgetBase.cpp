// Fill out your copyright notice in the Description page of Project Settings.


#include "GSUserWidgetBase.h"

void UGSUserWidgetBase::SynchronizeProperties()
{
	// If edited inside Editor this widget won't override custom members
	if(GetParent())
	{
		return;
	}
	Super::SynchronizeProperties();
}
