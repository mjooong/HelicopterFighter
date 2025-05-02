// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bot.generated.h"

UCLASS()
class HELICOPTERFIGHTER_API ABot : public AActor
{
	GENERATED_BODY()
	
public:	
	ABot();

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

public:	

private:
	// Components
	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> BotMesh;

};
