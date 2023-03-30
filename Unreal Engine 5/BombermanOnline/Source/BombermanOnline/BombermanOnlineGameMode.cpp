#include "BombermanOnlineGameMode.h"
#include "BombermanOnlineCharacter.h"
#include "UObject/ConstructorHelpers.h"

BombermanOnlineGameMode::BombermanOnlineGameMode()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));

	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}