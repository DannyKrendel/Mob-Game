#include "pch.h"
#include "Controller.h"

Controller::Controller() :
	left(VK_LEFT), right(VK_RIGHT), up(VK_UP), down(VK_DOWN), action(VK_SPACE)
{
}

Controller::Controller(int left, int right, int up, int down, int action) :
	left(left), right(right), up(up), down(down), action(action)
{
}
