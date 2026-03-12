#include "IsometricCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "InputActionValue.h"

AIsometricCharacter::AIsometricCharacter()
{
	PrimaryActorTick.TickInterval = 0.0f;

	// Don't rotate with camera
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.0f;
	GetCharacterMovement()->MaxWalkSpeedCrouched = 300.0f;

	// Create camera boom
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = CameraBoomLength;
	CameraBoom->bUsePawnControlRotation = false;
	CameraBoom->bInheritPitch = false;
	CameraBoom->bInheritYaw = false;
	CameraBoom->bInheritRoll = false;

	// Create isometric camera
	IsometricCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("IsometricCamera"));
	IsometricCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	IsometricCamera->bUsePawnControlRotation = false;
	IsometricCamera->FieldOfView = 90.0f;
}

void AIsometricCharacter::BeginPlay()
{
	Super::BeginPlay();
	SetupIsometricCamera();
}

void AIsometricCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	// Update movement speed
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
}

void AIsometricCharacter::SetupIsometricCamera()
{
	// Set camera boom rotation for isometric view
	FRotator CameraBoomRotation(CameraPitch, CameraYaw, CameraRoll);
	CameraBoom->SetWorldRotation(CameraBoomRotation);
	CameraBoom->TargetArmLength = CameraBoomLength;

	// Set camera to not rotate with character
	GetCharacterMovement()->bOrientRotationToMovement = true;
}

void AIsometricCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Input is handled by IsometricPlayerController
	// This function is here for future extensions
}
