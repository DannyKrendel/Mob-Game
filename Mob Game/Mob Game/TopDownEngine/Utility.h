#pragma once
#include "Vector2.h"

void showConsoleCursor(bool showFlag);
void gotoPos(const Vector2 &pos);
Vector2 getConsoleWindowSize();
void setConsoleWindowSize(int width, int height);
void SetColor(int fgColor);