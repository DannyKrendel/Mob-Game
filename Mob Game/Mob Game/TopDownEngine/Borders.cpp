#include "pch.h"
#include "Borders.h"

Borders::Borders()
{
}

Borders::Borders(int left, int top, int right, int bottom)
{
	this->left = left;
	this->top = top;
	this->right = right;
	this->bottom = bottom;
}

Borders::Borders(Vector2 topLeft, Vector2 bottomRight)
{
	left = topLeft.x;
	top = topLeft.y;
	right = bottomRight.x;
	bottom = bottomRight.y;
}

bool Borders::isInside(const Vector2 & point)
{
	return point.x >= left && point.x < right && point.y >= top && point.y < bottom;
}
