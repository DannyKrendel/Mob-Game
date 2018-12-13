#include "pch.h"
#include "Player.h"

Player::Player() : GameObject() {}

Player::Player(Controller controller, char sym, int speed, Color color) : GameObject(sym, speed, color), controller(controller)
{
}

Controller * Player::getController()
{
	return &controller;
}

bool Player::handleMovement(Borders borders)
{
	bool isThereMovement = false;
	Vector2 offset;

	if (controller.left.isDown())
	{
		offset += Vector2::left;
	}
	if (controller.right.isDown())
	{
		offset += Vector2::right;
	}
	if (controller.up.isDown())
	{
		offset += Vector2::up;
	}
	if (controller.down.isDown())
	{
		offset += Vector2::down;
	}

	if (offset != Vector2::zero)
	{
		isThereMovement = true;

		Vector2 tempPos = getNextPosition(offset);

		if (borders.isInside(tempPos))
		{
			erase();
			move(offset);
		}
	}
	
	draw();

	return isThereMovement;
}