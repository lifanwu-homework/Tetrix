#pragma once
void control_loop()
{
	char click;
	while (1) {
		if (_kbhit())
		{
			click = _getch();
			B.change(click);
		}
		Sleep(50);
	}

}
