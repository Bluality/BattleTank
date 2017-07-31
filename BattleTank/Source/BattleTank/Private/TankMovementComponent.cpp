// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "Engine/World.h"
#include "TankTrack.h"

void UTankMovementComponent::IntendMoveForward(float Throw)
{

	UE_LOG(LogTemp, Warning, TEXT("%f: Intend move forward throw: %f"), GetWorld()->GetTimeSeconds(), Throw);
	
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);

}

void UTankMovementComponent::Initialise(UTankTrack * LeftTrackToSet, UTankTrack * RightTrackToSet)
{
	if (!LeftTrackToSet || !RightTrackToSet) return;
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;

	// TODO prevent double speed due to double input
}
