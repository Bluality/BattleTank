// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

#include "GameFramework/PlayerController.h"
#include "GameFramework/Pawn.h"
#include "Engine/World.h"

#include "TankAimingComponent.h"

// Depends on movement component via pathfinding system

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();

	if (!ensure(PlayerTank && PlayerTank)) return;

	//  Move towards the player
	MoveToActor(PlayerTank, AcceptanceRadius); // TODO check radius is in CM

	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	AimingComponent->AimAt(PlayerTank->GetActorLocation());

	// Fire if ready
	AimingComponent->Fire();
}
