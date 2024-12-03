#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <mmsystem.h>
#include <fstream> 
#include <limits> 
using namespace std;

void clearScreen();
void nenSound();
void moveSound();
void choseSound();
void GotoXY(int column, int line);
void setColor(int color);
void ShowBlinkingCursor(bool isVisible);
void fixConsoleWindow();
void setConsoleWindow(int w, int h);
void setConsoleWindowSize(int w, int h);
void setScreenBufferSize(int w, int h);
void DisableSelection();