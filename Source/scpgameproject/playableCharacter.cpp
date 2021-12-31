// Fill out your copyright notice in the Description page of Project Settings.


#include "playableCharacter.h"

// Sets default values
AplayableCharacter::AplayableCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	bUseControllerRotationYaw = false;
	bUseControllerRotationPitch = false;
	cam = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	cam->AttachTo(RootComponent);
}

// Called when the game starts or when spawned
void AplayableCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AplayableCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
  
// Called to bind functionality to input
void AplayableCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("Horizontal", this, &AplayableCharacter::horizontalMovement);
	PlayerInputComponent->BindAxis("Vertical", this, &AplayableCharacter::verticalMovement);
	PlayerInputComponent->BindAxis("HorizontalRot", this, &AplayableCharacter::HorizontalRot);
	PlayerInputComponent->BindAxis("VerticalRot", this, &AplayableCharacter::VerticalRot);
}
void AplayableCharacter::horizontalMovement(float value) {
	if (value) {
		AddMovementInput(GetActorRightVector(), value);
	}
}
void AplayableCharacter::verticalMovement(float value) {
	if (value) {
		AddMovementInput(GetActorForwardVector(), value);
	}
}
void AplayableCharacter::HorizontalRot(float value) {
	if (value) {
		AddActorLocalRotation(FRotator(0, value, 0));
	}
}
void AplayableCharacter::VerticalRot(float value) {
	if (value) {
		float temp = cam->GetRelativeRotation().Pitch + value;

		if (temp <= 65 && temp >= -65) {
			cam->AddLocalRotation(FRotator(value, 0, 0));
		}
	}
	
}
