#include "pch.h"
#include "Key.h"

Key::Key(int keyCode) : keyCode(keyCode)
{
}

bool Key::isDown()
{
	return (GetAsyncKeyState(keyCode) & (1 << 16));
}

bool Key::isPressed()
{
	bool temp = previousState;
	previousState = isDown();
	return (previousState && !temp);
}

bool Key::isReleased()
{
	bool temp = previousState;
	previousState = isDown();
	return (!previousState && temp);
}