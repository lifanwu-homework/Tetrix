#pragma once
void main_loop()
{
	HideCursor();
	B._init_Block();
	int t = 0;
	for (;; Sleep(20))
	{
		t++;
		if (t%4==0)
		{
			B.y++;
			if (B.crash())
			{
				if (B.y <= 0)exit(0);
				B.y--;
				build_room(B);
				B._init_Block();
				delete_line();
			}
		}
		system("cls");
		print_room();
		B.print();

		
	}
}
