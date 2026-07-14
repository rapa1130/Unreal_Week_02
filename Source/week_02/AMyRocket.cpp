// Fill out your copyright notice in the Description page of Project Settings.


#include "AMyRocket.h"

// Sets default values
AAMyRocket::AAMyRocket()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAMyRocket::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAMyRocket::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

