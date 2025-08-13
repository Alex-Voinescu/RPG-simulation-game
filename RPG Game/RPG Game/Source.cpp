#include "Game.h"


int main()
{
	Game* instance = Game::getInstance();
	instance->Initialize();
	instance->Run();
}