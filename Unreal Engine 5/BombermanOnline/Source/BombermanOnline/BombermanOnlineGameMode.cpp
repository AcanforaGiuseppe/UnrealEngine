#include "BombermanOnlineGameMode.h"
#include "BombermanOnlineCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABombermanOnlineGameMode::ABombermanOnlineGameMode()
{
	// Set default pawn class to Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));

	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}