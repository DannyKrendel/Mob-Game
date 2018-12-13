#include "pch.h"
#include "GameObject.h"
#include "Utility.h"

GameObject::GameObject()
{
	sym = '?';
}

GameObject::GameObject(char sym, int speed, Color color)
{
	this->sym = sym;
	this->speed = speed;
	this->color = color;
}

GameObject::GameObject(const GameObject & gameObject)
{
	this->position = gameObject.position;
	this->sym = gameObject.sym;
	this->speed = gameObject.speed;
	this->color = gameObject.color;
}

Vector2 GameObject::getPosition()
{
	return position;
}

char GameObject::getSym()
{
	return sym;
}

int GameObject::getSpeed()
{
	return speed;
}

void GameObject::setPosition(Vector2 position)
{
	this->position = position;
}

void GameObject::setSym(char sym)
{
	this->sym = sym;
}

void GameObject::setSpeed(int speed)
{
	this->speed = speed;
}

Vector2 GameObject::getNextPosition(Vector2 offset)
{
	return position + offset * speed;
}

void GameObject::move(Vector2 offset)
{
	setPosition(position + offset * speed);
}

void GameObject::draw()
{
	gotoPos(position);
	SetColor(color.color);
	std::cout << sym;
	SetColor(FG_LIGHTGRAY);
}

void GameObject::erase()
{
	gotoPos(position);
	std::cout << ' ';
}

bool GameObject::operator==(const GameObject & rhs)
{
	return this->position == rhs.position && this->sym == rhs.sym;
}
