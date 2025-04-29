// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputActionValue.h"
#include "Helicopter.generated.h"

// Forward Declare
class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;

UCLASS()
class HELICOPTERFIGHTER_API AHelicopter : public APawn
{
	GENERATED_BODY()

public:
	AHelicopter();

	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

private:
	// Components
	UPROPERTY(VisibleAnywhere, Category = "Helicopter")
	TObjectPtr<UStaticMeshComponent> HelicopterMesh;

	UPROPERTY(VisibleAnywhere, Category = "Helicopter")
	TObjectPtr<USpringArmComponent> HelicopterSpringArm;

	UPROPERTY(VisibleAnywhere, Category = "Helicopter")
	TObjectPtr<UCameraComponent> HelicopterCamera;

	// Movement
	UPROPERTY(EditAnywhere, Category = "Movement")
	TObjectPtr<UInputMappingContext> IMC_HelicopterMovement;

	UPROPERTY(EditAnywhere, Category = "Movement")
	TObjectPtr<UInputAction> IA_MoveForward;
	
	UPROPERTY(EditAnywhere, Category = "Movement")
	TObjectPtr<UInputAction> IA_MoveRight;
	
	UPROPERTY(EditAnywhere, Category = "Movement")
	TObjectPtr<UInputAction> IA_MoveUp;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float HelicopterMovementSpeed = 500.f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float HelicopterMovementRightValue = 300.f;


	// Movement Functions
	void MoveForward(const FInputActionValue& InputActionValue);
	void MoveRight(const FInputActionValue& InputActionValue);
	void MoveUp(const FInputActionValue& InputActionValue);

public:	

};
