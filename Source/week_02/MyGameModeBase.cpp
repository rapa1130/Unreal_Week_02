// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "MyPlayerController.h"
#include "MyPawn.h"

AMyGameModeBase::AMyGameModeBase()
{
	UE_LOG(LogTemp, Warning, TEXT("Hello World"));
	
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(0, 3.0f, FColor::Red, TEXT("GENine Helloworld"));
	}

	DefaultPawnClass = AMyPawn::StaticClass();
	PlayerControllerClass = AMyPlayerController::StaticClass();
}
	