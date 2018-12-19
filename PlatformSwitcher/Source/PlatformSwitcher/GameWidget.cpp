// Fill out your copyright notice in the Description page of Project Settings.

#include "GameWidget.h"

void UGameWidget::Load()
{
	const FName textBlockName = FName(TEXT("Message"));

	if (messageText == nullptr)
	{
		messageText = (UTextBlock*)(WidgetTree->FindWidget(textBlockName));
	}
}

void UGameWidget::OnGameOver(bool win)
{
	if (messageText != nullptr)
	{
		if (win)
		{
			messageText->SetText(FText::FromString(FString(TEXT("You won! \nPress R to play again!"))));
		}
		else
		{
			messageText->SetText(FText::FromString(FString(TEXT("You loose! \nPress R to play again!"))));
		}
	}
}