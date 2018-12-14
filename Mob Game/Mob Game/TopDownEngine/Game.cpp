#include "pch.h"
#include "Game.h"
#include "Utility.h"

Game::Game(Borders borders, Player *player, Mob *mob, int maxMobs) : borders(borders)
{
	this->player = player;
	this->mob = mob;
	this->maxMobs = maxMobs;
}

void Game::run(int delayMs)
{
	player->setPosition(Vector2(borders.right / 2, borders.bottom / 2));
	gotoPos(Vector2(borders.right / 2 - 7, borders.bottom / 2 - 2));
	std::cout << "ARROWS TO MOVE";

	while (player->handleMovement(borders) == false) {}

	gotoPos(Vector2(borders.right / 2 - 7, borders.bottom / 2 - 2));
	std::cout << std::string(borders.right, ' ');

	displayCoinsText(Vector2::zero);
	displayShopText(Vector2(14, 0));

	while (true)
	{
		displayCoinsText(Vector2::zero);

		if (countMs >= mobSpawnDelayMs)
		{
			countMs = 0;

			if (mobs.size() < maxMobs)
			{
				mobs.push_back(Mob(*mob));
				mobs.back().randomizePos(borders);
			}
		}
		else
		{
			countMs += delayMs;
		}

		for (Mob &m : mobs)
		{
			m.behaviour(borders);
		}

		player->handleMovement(borders);

		checkPlayerOnMob();

		checkActionPressed();

		Sleep(delayMs);
	}
}

void Game::checkPlayerOnMob()
{
	for (auto it = mobs.begin(); it != mobs.end(); ++it)
	{
		if (it->getPosition() == player->getPosition())
		{
			killMob(it);
			break;
		}
	}
}

void Game::killMob(std::vector<Mob>::iterator mob)
{
	gotoPos(mob->getPosition());
	mobs.erase(mob);
	coins++;
}

void Game::displayCoinsText(Vector2 pos)
{
	std::string tempText = "Coins: " + std::to_string(coins);
	if (tempText != coinsText)
	{
		coinsText = tempText;
		gotoPos(pos);
		std::cout << std::string(10, ' ');
		gotoPos(pos);
		std::cout << coinsText;
	}
}

void Game::displayShopText(Vector2 pos)
{
	std::string shopText = "[Space] +1 speed (" + std::to_string(speedUpgradeCost) + " coins)";
	gotoPos(pos);
	std::cout << std::string(borders.right, ' ');
	gotoPos(pos);
	std::cout << shopText;
}

void Game::buySpeedUpgrade()
{
	coins -= speedUpgradeCost;
	player->setSpeed(player->getSpeed() + 1);
}

void Game::checkActionPressed()
{
	if (coins >= speedUpgradeCost && player->getController()->action.isPressed())
		buySpeedUpgrade();
}
