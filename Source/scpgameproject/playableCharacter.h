// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "playableCharacter.generated.h"

UCLASS()
class SCPGAMEPROJECT_API AplayableCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AplayableCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	//Called to set default value of movement 0.00
private: 
	void horizontalMovement(float value);
	void verticalMovement(float value); 
	void HorizontalRot(float value);
	void VerticalRot(float value);

	UPROPERTY()
		UCameraComponent* cam;

};
