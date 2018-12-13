#include "pch.h"
#include "Vector2.h"

Vector2::Vector2() : x(0), y(0)
{
}

Vector2::Vector2(int x, int y) : x(x), y(y)
{	
}

Vector2::Vector2(const COORD & coord)
{
	x = coord.X;
	y = coord.Y;
}

const Vector2 Vector2::zero = Vector2(0, 0);
const Vector2 Vector2::left = Vector2(-1, 0);
const Vector2 Vector2::right = Vector2(1, 0);
const Vector2 Vector2::up = Vector2(0, -1);
const Vector2 Vector2::down = Vector2(0, 1);

Vector2::operator COORD()
{
	return COORD{ static_cast<short>(x), static_cast<short>(y) };
}

Vector2 & Vector2::operator+=(const Vector2 &rhs)
{
	this->x += rhs.x;
	this->y += rhs.y;
	return *this;
}

Vector2 & Vector2::operator-=(const Vector2 &rhs)
{
	this->x -= rhs.x;
	this->y -= rhs.y;
	return *this;
}

bool Vector2::operator==(const Vector2 &rhs)
{
	return this->x == rhs.x && this->y == rhs.y;
}

bool Vector2::operator!=(const Vector2 &rhs)
{
	return !(*this == rhs);
}

Vector2 operator+(Vector2 lhs, const Vector2 &rhs)
{
	lhs += rhs;
	return lhs;
}

Vector2 operator-(Vector2 lhs, const Vector2 &rhs)
{
	lhs -= rhs;
	return lhs;
}

Vector2 operator*(Vector2 lhs, const int & rhs)
{
	lhs.x *= rhs;
	lhs.y *= rhs;
	return lhs;
}

Vector2 operator/(Vector2 lhs, const int & rhs)
{
	if (rhs != 0)
	{
		lhs.x /= rhs;
		lhs.y /= rhs;
	}
	return lhs;
}
