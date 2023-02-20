enum Screen
{
	MENU,
	GAME,
	CARD,
	SELECT,
	END
};
enum class Position
{
	NUN,
	ALL,
	SHORT,
	MID,
	LONG
};
enum class Fruction
{
	NUN,
	NILFGAARD,
	KINGDOMNORTH
};

const int screenWidth = GetSystemMetrics(SM_CXSCREEN),
		  screenHeight = GetSystemMetrics(SM_CYSCREEN);
int winWidth = screenWidth, winHeight = screenHeight;

#include "interface.h"
#include "card.h"
#include "player.h"
#include "decks.h"

Decks decks;
Player player;
bool  isMouseLeftFree = true, isMouseLeftPressed = false;
