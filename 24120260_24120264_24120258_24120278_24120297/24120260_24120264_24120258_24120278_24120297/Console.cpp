#include "Console.h"

// Hàm xóa màn hình (clear screen)
void clearScreen() {
#ifdef _WIN32
	system("color 70");
	system("cls"); // Dành cho Windows
#else
	system("clear"); // Dành cho Linux/Mac
#endif
}
void nenSound()
{
	PlaySound(TEXT("nhacNen.wav"), NULL, SND_FILENAME | SND_ASYNC);
}
void moveSound() {
	PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
}
void choseSound() {
	PlaySound(TEXT("chose.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

//screen: goto [x,y]
void GotoXY(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void ShowBlinkingCursor(bool isVisible) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;

	// Lấy thông tin con trỏ hiện tại
	GetConsoleCursorInfo(hConsole, &cursorInfo);

	// Cài đặt con trỏ nhấp nháy và hiện thị dựa trên tham số truyền vào
	cursorInfo.bVisible = isVisible;
	cursorInfo.dwSize = isVisible ? 25 : 2; 
	SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void fixConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void setConsoleWindow(int w, int h)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);

	MoveWindow(console, r.left, r.top, w, h, TRUE);
}

void setConsoleWindowSize(int width, int height) {
	SMALL_RECT rect;
	COORD coord;
	coord.X = width;
	coord.Y = height;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	// Đặt kích thước buffer trước
	SetConsoleScreenBufferSize(hConsole, coord);

	// Cập nhật kích thước cửa sổ
	rect.Left = 0;
	rect.Top = 0;
	rect.Right = width - 1;
	rect.Bottom = height - 1;
	SetConsoleWindowInfo(hConsole, TRUE, &rect);
}

void setScreenBufferSize(int w, int h) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD NewSize;
	NewSize.X = w;
	NewSize.Y = h;

	SetConsoleScreenBufferSize(hStdout, NewSize);
}

void DisableSelection() {
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);

	SetConsoleMode(hStdin, ~ENABLE_QUICK_EDIT_MODE);
}