#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputActionValue.h"
#include "IsometricPlayerController.generated.h"

class AIsometricCharacter;
class UInputMappingContext;
class UInputAction;

/**
 * Player controller for isometric perspective games
 * Handles input redirection for isometric movement (WASD controls)
 */
UCLASS()
class QIXX_API AIsometricPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AIsometricPlayerController();

protected:
	virtual void SetupInputComponent() override;
	virtual void BeginPlay() override;

	// Enhanced Input System
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputMappingContext> DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> LookAction;

	// Callbacks for input
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

	AIsometricCharacter* IsometricCharacter;
};
