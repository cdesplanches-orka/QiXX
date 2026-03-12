#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "IsometricGameMode.generated.h"

/**
 * Game mode for isometric view games
 */
UCLASS()
class QIXX_API AIsometricGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	AIsometricGameMode();
};
