#include "Game.h"
#include <fstream>
#include <algorithm>

const int Game::enemiesCount = 15;

Game* Game::instance = nullptr;

Game* Game::getInstance()
{
	if (instance == nullptr)
		instance = new Game();

	return instance;
}

void Game::Initialize()
{
	std::ifstream in("characters.txt");
	in >> mainCharacter;
	enemies = new Character[enemiesCount];
	for (int i = 0;i < enemiesCount;i++)
	{
		in >> enemies[i];
	}
}

void Game::Run()
{

	std::sort(enemies, enemies + enemiesCount);
	int i = 0;
	bool succes = true;
	int choice = 0;
	while (!mainCharacter.isDead() && i < enemiesCount)
	{

		while (!enemies[i].isDead())
		{
			std::cout << "You: ";
			mainCharacter.outputInGame();
			std::cout << "Enemy: ";
			enemies[i].outputInGame();
			std::cout << "Choose your next move! [1] heal [2] attack \n";
			std::cin >> choice;
			switch (choice)
			{
			case 1:
				if (mainCharacter.getHealthPotionsCount() > 0)
					mainCharacter.heal();
				break;
			case 2:
				mainCharacter.attack(enemies[i]);
				break;
			default:
				std::cout << "Well seems like you skipped your turn :/ \n";
				break;
			}
			std::cout << "\n";
			enemies[i].attack(mainCharacter);
			if (mainCharacter.isDead())
			{
				std::cout << enemies[i].getName() << " has eliminated you! \n";
				succes = false;
				break;
			}
		}
		if (succes)
		{
			std::cout << mainCharacter.getName() << " eliminated enemy " << enemies[i].getName() << "!\n";
			if (i % 2 == 1)
				mainCharacter.lvlUp();
		}
		i++;
	}
	if (succes)
		std::cout << "succes, well done champ: " << mainCharacter;
	else
		std::cout << "Too bad, better luck next time champ \n";

}
