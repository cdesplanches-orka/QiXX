#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "IsometricCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UCharacterMovementComponent;

/**
 * Character for isometric perspective games
 * Features isometric camera setup and movement
 */
UCLASS()
class QIXX_API AIsometricCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AIsometricCharacter();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	// Camera component for isometric view
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<USpringArmComponent> CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UCameraComponent> IsometricCamera;

	// Character stats
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float Health = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float WalkSpeed = 600.0f;

	// Isometric camera settings
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Isometric")
	float CameraBoomLength = 1200.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Isometric")
	float CameraPitch = -45.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Isometric")
	float CameraRoll = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Isometric")
	float CameraYaw = 45.0f;

protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void SetupIsometricCamera();
};
