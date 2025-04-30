// Fill out your copyright notice in the Description page of Project Settings.


#include "Helicopter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputAction.h"

AHelicopter::AHelicopter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	HelicopterMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("HelicopterMesh"));
	RootComponent = HelicopterMesh;

	HelicopterSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("HelicopterSpringArm"));
	HelicopterSpringArm->SetupAttachment(HelicopterMesh);
	HelicopterSpringArm->SetRelativeLocation(FVector(0.f, 0.f, 300.f));
	HelicopterSpringArm->TargetArmLength = 1200.f;
	HelicopterSpringArm->SocketOffset = FVector(0.f, 0.f, 400.f);

	HelicopterCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("HelicopterCamera"));
	HelicopterCamera->SetupAttachment(HelicopterSpringArm);
	HelicopterCamera->FieldOfView = 100.f;
}

void AHelicopter::BeginPlay()
{
	Super::BeginPlay();
	
	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(IMC_HelicopterMovement, 0);
		}
	}
}

void AHelicopter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AHelicopter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInput->BindAction(IA_MoveForward, ETriggerEvent::Triggered, this, &AHelicopter::MoveForward);
		EnhancedInput->BindAction(IA_MoveUp, ETriggerEvent::Triggered, this, &AHelicopter::MoveUp);
		EnhancedInput->BindAction(IA_MoveRight, ETriggerEvent::Triggered, this, &AHelicopter::MoveRight);
		EnhancedInput->BindAction(IA_LookAround, ETriggerEvent::Triggered, this, &AHelicopter::LookAround);
	}

}

void AHelicopter::MoveForward(const FInputActionValue& InputActionValue)
{
	const float InputAxisValue = InputActionValue.Get<float>();

	if (UWorld* World = GetWorld())
	{
		float Speed = HelicopterMovementSpeed * InputAxisValue * World->GetDeltaSeconds();
		AddActorLocalOffset(FVector(Speed, 0.f, 0.f));
	}
	
}

void AHelicopter::MoveUp(const FInputActionValue& InputActionValue)
{
	const float InputAxisValue = InputActionValue.Get<float>();
	if (UWorld* World = GetWorld())
	{
		float Speed = HelicopterMovementSpeed * InputAxisValue * World->GetDeltaSeconds();
		AddActorLocalOffset(FVector(0.f, 0.f, Speed));
	}
}

void AHelicopter::MoveRight(const FInputActionValue& InputActionValue)
{
	const float InputAxisValue = InputActionValue.Get<float>();
	if (UWorld* World = GetWorld())
	{
		float Speed = HelicopterMovementRightValue * InputAxisValue * World->GetDeltaSeconds();
		AddActorLocalOffset(FVector(0.f, Speed, 0.f));
	}
}

void AHelicopter::LookAround(const FInputActionValue& InputActionValue)
{
	FVector2D LookAroundValue = InputActionValue.Get<FVector2D>();

	if (UWorld* World = GetWorld())
	{
		AddControllerYawInput(LookAroundValue.X * TurnRate * World->GetDeltaSeconds());
		AddControllerPitchInput(LookAroundValue.Y * TurnRate * World->GetDeltaSeconds());
	}
	
}
