#pragma once
#include "Vector2.h"

struct Borders
{
public:
	int left, top, right, bottom;

	Borders();
	Borders(int left, int top, int right, int bottom);
	Borders(Vector2 topLeft, Vector2 bottomRight);
	bool isInside(const Vector2 &point);
};

