#pragma once


/*#define NONE          "/033[m"  
#define RED           "/033[0;32;31m"  
#define LIGHT_RED     "/033[1;31m"   
#define GREEN         "/033[0;32;32m"   
#define LIGHT_GREEN   "/033[1;32m"   
#define BLUE          "/033[0;32;34m"   
#define LIGHT_BLUE    "/033[1;34m"   
#define DARY_GRAY     "/033[1;30m"   
#define CYAN          "/033[0;36m"   
#define LIGHT_CYAN    "/033[1;36m"   
#define PURPLE        "/033[0;35m"   
#define LIGHT_PURPLE "/033[1;35m"   
#define BROWN         "/033[0;33m"   
#define YELLOW        "/033[1;33m"   
#define LIGHT_GRAY    "/033[0;37m"   
#define WHITE         "/033[1;37m"   
*/

#define RED           31
#define GREEN         32
#define YELLOW        33
#define BLUE          34
#define PURPLE        35
#define CYAN          36
#define WHITE         37

HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
void gotoxy(short x, short y) {
	COORD coord = { x,y };
	SetConsoleCursorPosition(handle, coord);
}
void HideCursor() {
	CONSOLE_CURSOR_INFO cursor_info = { 1,0 };
	SetConsoleCursorInfo(handle, &cursor_info);
}

void print_pixel(int x,int y,int color)
{
	if (y < 0)return;
	gotoxy(2 * x, y);
	printf("\033[%dm¡ö\033[0m",color);
}
