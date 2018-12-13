#pragma once
#include "Key.h"

struct Controller
{
public:
	Key left, right, up, down, action;

	Controller();
	Controller(int left, int right, int up, int down, int action);
};