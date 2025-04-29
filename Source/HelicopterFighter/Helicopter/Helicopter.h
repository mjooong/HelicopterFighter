// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Helicopter.generated.h"

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
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> HelicopterMesh;

public:	
	// Setters and Getters

};
