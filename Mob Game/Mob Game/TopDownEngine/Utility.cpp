#include "pch.h"
#include "Utility.h"

void showConsoleCursor(bool showFlag)
{
	CONSOLE_CURSOR_INFO cursorInfo;

	HANDLE stdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleCursorInfo(stdOut, &cursorInfo);
	cursorInfo.bVisible = showFlag;
	SetConsoleCursorInfo(stdOut, &cursorInfo);
}

void gotoPos(const Vector2 &pos) {
	HANDLE stdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(stdOut, const_cast<Vector2&>(pos));
}

Vector2 getConsoleWindowSize()
{
	CONSOLE_SCREEN_BUFFER_INFO bufferInfo;

	HANDLE stdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(stdOut, &bufferInfo);
	return bufferInfo.dwSize;
}

void setConsoleWindowSize(int width, int height)
{
	COORD size = { width, height };
	SMALL_RECT rect = { 0, 0, width - 1, height - 1};

	HANDLE stdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleScreenBufferSize(stdOut, size);
	SetConsoleWindowInfo(stdOut, TRUE, &rect);
}

void SetColor(int fgColor)
{
	WORD wColor;

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		wColor = (csbi.wAttributes & 0xF0) + (fgColor & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
}