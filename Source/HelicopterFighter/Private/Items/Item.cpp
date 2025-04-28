// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Item.h"

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AItem::BeginPlay()
{
	Super::BeginPlay();
	
	int32 Average = AddValue<int32>(34, 44);
	float AverageFloat = AddValue<float>(23.4f, 45.7f);
	FVector AverageVector = AddValue<FVector>(FVector(3, 5, 8), FVector(6, 9, 12));

	UE_LOG(LogTemp, Warning, TEXT("Average Value is: %d"), Average);
	UE_LOG(LogTemp, Warning, TEXT("Average float Value is: %f"), AverageFloat);
	UE_LOG(LogTemp, Warning, TEXT("Average Vector Value is: %f, %f, %f"), AverageVector.X, AverageVector.Y, AverageVector.Z);
}

void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
