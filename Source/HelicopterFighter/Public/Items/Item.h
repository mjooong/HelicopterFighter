// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class HELICOPTERFIGHTER_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	AItem();

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

public:	
	// Setter and Getter.
	template<typename T>
	T AddValue(T Value1, T Value2);

private:
	
};

template<typename T>
inline T AItem::AddValue(T Value1, T Value2)
{
	return Value1 + Value2;
}
