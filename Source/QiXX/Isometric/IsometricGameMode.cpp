#include "IsometricGameMode.h"
#include "IsometricCharacter.h"
#include "IsometricPlayerController.h"

AIsometricGameMode::AIsometricGameMode()
{
	// Set default classes
	DefaultPawnClass = AIsometricCharacter::StaticClass();
	PlayerControllerClass = AIsometricPlayerController::StaticClass();
}
