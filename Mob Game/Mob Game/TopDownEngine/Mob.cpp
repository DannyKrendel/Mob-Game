#include "pch.h"
#include "Mob.h"

Mob::Mob() : GameObject()
{
}

Mob::Mob(char sym, int speed, Color color) : GameObject(sym, speed, color)
{
}

Mob::Mob(const Mob & mob) : GameObject(mob)
{
}

Mob::~Mob()
{
}

void Mob::randomizePos(Borders borders)
{
	position.x = rand() % (borders.right - borders.left) + borders.left;
	position.y = rand() % (borders.bottom - borders.top) + borders.top;
}

void Mob::behaviour(Borders borders)
{
	Vector2 offset;

	int rndNum = rand() % 5;
	switch (rndNum)
	{
	case 0:
		offset = Vector2::zero * speed;
		break;
	case 1:
		offset = Vector2::left * speed;
		break;
	case 2:
		offset = Vector2::right * speed;
		break;
	case 3:
		offset = Vector2::up * speed;
		break;
	case 4:
		offset = Vector2::down * speed;
		break;
	}

	if (offset != Vector2::zero)
	{
		Vector2 tempPos = getNextPosition(offset);

		if (borders.isInside(tempPos))
		{
			erase();
			move(offset);
		}
	}

	draw();
}

bool Mob::operator==(const Mob & rhs)
{
	return static_cast<GameObject>(*this) == static_cast<GameObject>(rhs);
}
