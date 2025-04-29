// Fill out your copyright notice in the Description page of Project Settings.


#include "Helicopter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "InputMappingContext.h"

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
	
}

void AHelicopter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AHelicopter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

