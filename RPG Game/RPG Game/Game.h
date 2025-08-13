#pragma once
#pragma once
#include <string>
#include "Character.h"

class Game
{
public:
	static const int enemiesCount;
	static Game* getInstance();
	~Game() {}
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	void Initialize();
	void Run();
private:
	Game() = default;

private:
	static Game* instance;
	Character mainCharacter;
	Character* enemies;
};

