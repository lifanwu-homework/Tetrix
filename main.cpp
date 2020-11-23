#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<Windows.h>
#include<thread>
#include<conio.h>
#include"_cursor.h"
#include"blocks.h"

#include"main_loop.h"
#include"control_loop.h"
using namespace std;


int main()
{
	srand(time(NULL));
	thread _print(main_loop);
	thread _control(control_loop);
	_print.join();
	_control.join();
}
