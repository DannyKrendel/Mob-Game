#pragma once
#include "GameObject.h"
#include "Controller.h"
#include "Borders.h"

class Player: public GameObject
{
private:
	Controller controller;
public:
	Player();
	Player(Controller controller, char sym, int speed = 1, Color color = Color());

	Controller *getController();
	bool handleMovement(Borders borders);
};

