#pragma once

struct Vector2
{
public:
	int x, y;

	Vector2();
	Vector2(int x, int y);
	Vector2(const COORD &coord);

	static const Vector2 zero;
	static const Vector2 left;
	static const Vector2 right;
	static const Vector2 up;
	static const Vector2 down;

	operator COORD();
	Vector2 &operator+=(const Vector2& rhs);
	Vector2 &operator-=(const Vector2& rhs);
	friend Vector2 operator+(Vector2 lhs, const Vector2 &rhs);
	friend Vector2 operator-(Vector2 lhs, const Vector2 &rhs);
	friend Vector2 operator*(Vector2 lhs, const int &rhs);
	friend Vector2 operator/(Vector2 lhs, const int &rhs);
	bool operator==(const Vector2 &rhs);
	bool operator!=(const Vector2 &rhs);
};