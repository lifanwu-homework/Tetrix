#pragma once
#define MAXBLOCK 6
#define BLOCKSIZE 4
#define MAX_X 10
#define MAX_Y 20

char room[MAX_X][MAX_Y] = { 0 };

void print_room()
{
	for (int i = 0; i < MAX_X; i++)
		for (int j = 0; j < MAX_Y; j++)
		{
			if (room[i][j])print_pixel(i, j, room[i][j]);
		}
	for (int i = 0; i < MAX_X; i++)
		print_pixel(i, MAX_Y, WHITE);
	for (int j = 0; j <= MAX_Y; j++)
		print_pixel(MAX_X, j, WHITE);
}


char blocks[MAXBLOCK][4][BLOCKSIZE][BLOCKSIZE] = {
	{{{0,0,0,0},{0,0,0,0},{1,1,1,1},{0,0,0,0}},
	{{0,1,0,0},{0,1,0,0},{0,1,0,0},{0,1,0,0}},
	{{0,0,0,0},{1,1,1,1},{0,0,0,0},{0,0,0,0}},
	{{0,0,1,0},{0,0,1,0},{0,0,1,0},{0,0,1,0}}},

	{{{0,0,0,0},{0,1,1,0},{0,1,1,0},{0,0,0,0}},
	{{0,0,0,0},{0,1,1,0},{0,1,1,0},{0,0,0,0}},
	{{0,0,0,0},{0,1,1,0},{0,1,1,0},{0,0,0,0}},
	{{0,0,0,0},{0,1,1,0},{0,1,1,0},{0,0,0,0}}},

	{{{0,0,0,0},{0,1,0,0},{1,1,1,0},{0,0,0,0}},
	{{0,1,0,0},{0,1,1,0},{0,1,0,0},{0,0,0,0}},
	{{0,0,0,0},{0,1,1,1},{0,0,1,0},{0,0,0,0}},
	{{0,0,0,0},{0,0,1,0},{0,1,1,0},{0,0,1,0}}},

	{{{0,0,0,0},{0,1,1,0},{0,0,1,1},{0,0,0,0}},
	{{0,0,0,0},{0,0,1,0},{0,1,1,0},{0,1,0,0}},
	{{0,0,0,0},{1,1,0,0},{0,1,1,0},{0,0,0,0}},
	{{0,0,1,0},{0,1,1,0},{0,1,0,0},{0,0,0,0}}},

	{{{0,0,0,0},{0,1,0,0},{0,1,1,1},{0,0,0,0}},
	{{0,0,0,0},{0,1,1,0},{0,1,0,0},{0,1,0,0}},
	{{0,0,0,0},{1,1,1,0},{0,0,1,0},{0,0,0,0}},
	{{0,0,1,0},{0,0,1,0},{0,1,1,0},{0,0,0,0}}},

	{{{0,0,0,0},{0,0,1,1},{0,1,1,0},{0,0,0,0}},
	{{0,0,0,0},{0,1,0,0},{0,1,1,0},{0,0,1,0}},
	{{0,0,0,0},{0,1,1,0},{1,1,0,0},{0,0,0,0}},
	{{0,1,0,0},{0,1,1,0},{0,0,1,0},{0,0,0,0}}},
};

class Block {
public:
	int x, y, form, dir,color;
	Block()
	{
		
	}

	void _init_Block()
	{
		this->x = 2;
		this->y = -4;
		this->form = rand() % MAXBLOCK;
		this->dir = rand() % 4;
		this->color = rand() % 7 + 31;
	}

	void print()
	{
		for (int i = 0; i < BLOCKSIZE; i++)
			for (int j = 0; j < BLOCKSIZE; j++)
			{
				if (blocks[form][dir][i][j])print_pixel(x+i, y+j, color);
			}
	}

	bool crash()
	{
		if (this->y < 0)return false;
		for (int i = 0; i < BLOCKSIZE; i++)
		{
			for (int j = 0; j < BLOCKSIZE; j++)
			{
				if (blocks[this->form][this->dir][i][j] )
				{
					
					if (i + this->x >= MAX_X || i + this->x < 0|| this->y + j >= MAX_Y)return true;
					if(room[i + this->x][j + this->y])
					return true;
				}
			}
		}
		return false;
	}


	void change(int click)
	{
		switch (click)
		{
		case 'q': {
			exit(0);
			break;
		}
		case 'w': {
			dir=(dir+1)%4;
			if (this->crash())
				dir = (dir - 1) % 4;
			else {
				/*system("cls");
				print_room();
				this->print();*/
			}
			break;
		}
		case 's': {
			y++;
				if (this->crash())
					y--;
				else {
					//system("cls");
					//print_room();
					//this->print();
				}
			break;
		}
		case 'a': {
			x--;
			if(this->crash())
			x++;
			break;
		}
		case 'd': {
			x++;
			if(this->crash())
			x--;
			break;
		}
		default: {
			break;
		}
		}
	}
}B;



void build_room(Block b)
{
	for (int i = 0; i < BLOCKSIZE; i++)
		for (int j = 0; j < BLOCKSIZE; j++)
		{
			if (blocks[b.form][b.dir][i][j])room[b.x + i][b.y + j] = b.color;
		}
}


void delete_line()
{
	int flag = 1;
	for (int n = MAX_Y - 1; n >= 0;)
	{
		flag = 1;
		for (int i = 0; i < MAX_X; i++)
		{
			flag *= room[i][n];
		}
		if (flag) {
			for (int i = 0; i < MAX_X; i++)
			{
				for (int j = n; j > 0; j--)
				{
					room[i][j] = room[i][j - 1];
				}
			}

		}
		else n--;
	}
}

