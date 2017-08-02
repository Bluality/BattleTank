// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
// Depends on movement component via pathfinding system

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (!ensure(PlayerTank)) return;

	//  Move towards the player
	MoveToActor(PlayerTank, AcceptanceRadius); // TODO check radius is in CM

	auto ControlledTank = Cast<ATank>(GetPawn());


	ControlledTank->AimAt(PlayerTank->GetActorLocation());

	// Fire if ready
	ControlledTank->Fire();
}
