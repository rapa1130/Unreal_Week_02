// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyRocket.generated.h"

class UNiagaraSystem;
//class USoundBase;

UCLASS()
class WEEK_02_API AMyRocket : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMyRocket();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void ProcessActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);

	UFUNCTION(BlueprintImplementableEvent)
	void CallCPPExecuteBP();
	UFUNCTION(BlueprintNativeEvent)
	void CallCPPExecuteBPDefault();
	void CallCPPExecuteBPDefault_Implementation();


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	TObjectPtr<UNiagaraSystem> ExpolsionTemplate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	TObjectPtr<USoundBase> ExplosionSound;
};