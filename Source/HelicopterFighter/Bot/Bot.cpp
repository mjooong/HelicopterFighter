// Fill out your copyright notice in the Description page of Project Settings.


#include "Bot.h"

// Sets default values
ABot::ABot()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BotMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BotMesh"));
	RootComponent = BotMesh;


}

void ABot::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

