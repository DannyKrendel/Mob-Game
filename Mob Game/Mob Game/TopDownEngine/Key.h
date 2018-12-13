#pragma once
struct Key
{
private:
	const int keyCode;
	bool previousState;
public:
	Key(int keyCode);

	bool isDown();
	bool isPressed();
	bool isReleased();
};