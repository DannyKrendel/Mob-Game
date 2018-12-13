#pragma once
#include "Vector2.h"
#include "Color.h"

class GameObject
{
protected:
	Color color;
	Vector2 position;
	char sym;
	int speed;
public:
	GameObject();
	GameObject(char sym, int speed = 1, Color color = Color());
	GameObject(const GameObject &gameObject);

	Vector2 getPosition();
	char getSym();
	int getSpeed();

	void setPosition(Vector2 position);
	void setSym(char sym);
	void setSpeed(int speed);

	Vector2 getNextPosition(Vector2 offset);
	void move(Vector2 offset);
	void draw();
	void erase();

	bool operator==(const GameObject &rhs);
};