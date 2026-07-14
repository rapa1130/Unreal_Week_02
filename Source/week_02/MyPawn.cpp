// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"

#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	RootComponent = Box;

	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	Body->SetupAttachment(Box);

	Left = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Left"));
	Left->SetupAttachment(Body);

	Right = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Right"));
	Right->SetupAttachment(Body);

	Left->SetWorldLocation(FVector(0, -50, 0));
	Right->SetWorldLocation(FVector(0, -50, 0));

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SprintArm"));
	SpringArm->SetupAttachment(Box);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	Movement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Movement"));

	ConstructorHelpers::FClassFinder<AMyRocket> ClassPath(TEXT("C:\Users\User\Documents\Unreal Projects\week_02\Content\Blueprints\BP_Rocket.uasset"))
}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Left->AddLocalRotation(FRotator(0, 0, 1440.0f *DeltaTime));
	Right->AddLocalRotation(FRotator(0, 0, 1440.0f *DeltaTime));
}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction(TEXT("Fire"), EInputEvent::IE_Pressed, this, &AMyPawn::Fire);

	PlayerInputComponent->BindAxis(TEXT("Pitch"), this, &AMyPawn::Pitch);
	PlayerInputComponent->BindAxis(TEXT("Roll"), this, &AMyPawn::Roll);

}

void AMyPawn::CallBlueprint(int Money, FString Name)
{
	UE_LOG(LogTemp, Warning, TEXT("Execute CPP"));
}

void AMyPawn::Fire()
{

	//GetWorld()->SpawnActor()
}

void AMyPawn::Pitch(float Value)
{

	float dT = UGameplayStatics::GetWorldDeltaSeconds(GetWorld());
	this->AddActorLocalRotation(dT * FRotator(Value, 0, 0) * 60);
}

void AMyPawn::Roll(float Value)
{
	float dT = UGameplayStatics::GetWorldDeltaSeconds(GetWorld());
	this->AddActorLocalRotation(dT * FRotator(0, 0, Value) * 60);
}

