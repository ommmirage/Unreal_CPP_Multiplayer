// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMenu.h"

bool UGameMenu::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) return false;

	if (!ensure(CancelBtn != nullptr)) return false;
	CancelBtn->OnClicked.AddDynamic(this, &UGameMenu::Cancel);

	if (!ensure(QuitBtn != nullptr)) return false;
	QuitBtn->OnClicked.AddDynamic(this, &UGameMenu::Quit);

	return true;
}

void UGameMenu::Cancel()
{
	Teardown();
}

void UGameMenu::Quit()
{
	if (MenuInterface != nullptr)
	{
		Teardown();
		MenuInterface->LoadMainMenu();
	}
}
