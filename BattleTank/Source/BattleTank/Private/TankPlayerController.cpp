// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possesing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possesing: %s"), *ControlledTank->GetName());
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
	UE_LOG(LogTemp, Warning, TEXT("Player controller ticking"));

}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) return;

	FVector HitLocation; // out parameter
	if (GetSightRayHitRotation(HitLocation)) // Get world location il linetrace trough crosshair
	{
		// If it hits the landscape
		UE_LOG(LogTemp, Warning, TEXT("Hit location: %s"), *HitLocation.ToString());

		// TODO Tell controlled tank to aim at this point
	}
}

bool ATankPlayerController::GetSightRayHitRotation(FVector& OutHitLocation) const
{
	OutHitLocation = FVector(1.0f);
	return true;
}
