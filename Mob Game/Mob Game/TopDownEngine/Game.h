#pragma once
#include "Player.h"
#include "Mob.h"

class Game
{
private:
	const Borders borders;
	Player *player;
	Mob *mob;
	std::vector<Mob> mobs;
	int mobSpawnDelayMs = 1000;
	int countMs;
	int maxMobs;

	int coins;
	int speedUpgradeCost = 5;

	std::string coinsText;
	std::string shopText;
public:
	Game(Borders borders, Player *player, Mob *mob, int maxMobs);

	void run(int delayMs);
	void checkPlayerOnMob();
	void killMob(std::vector<Mob>::iterator mob);
	void displayCoinsText(Vector2 pos);
	void displayShopText(Vector2 pos);
	void buySpeedUpgrade();
	void checkActionPressed();
};