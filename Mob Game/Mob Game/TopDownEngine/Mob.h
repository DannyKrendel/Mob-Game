#pragma once
#include "GameObject.h"
#include "Borders.h"

class Mob : public GameObject
{
public:
	Mob();
	Mob(char sym, int speed = 1, Color color = Color());
	Mob(const Mob &mob);
	~Mob();

	void randomizePos(Borders borders);
	void behaviour(Borders borders);

	bool operator==(const Mob &rhs);
};

