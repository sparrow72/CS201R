#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void InitializeGrid(int grid[5][5]);
void DrawGrid(int grid[5][5]);
void ClearScreen();

void SlideUp(int grid[5][5]);
void SlideDown(int grid[5][5]);
void SlideLeft(int grid[5][5]);
void SlideRight(int grid[5][5]);

int main()
{
	srand(time(NULL));
	int grid[5][5];
	InitializeGrid(grid);

	grid[2][2] = 2;

	bool done = false;
	while (!done)
	{
		ClearScreen();
		DrawGrid(grid);

		cout << endl << "[w] up \t [s] down \t [a] left \t [d] right" << endl;
		char choice;
		cin >> choice;

		switch (choice)
		{
		case 'w':
			SlideUp(grid);
			break;

		case 's':
			SlideDown(grid);
			break;

		case 'a':
			SlideLeft(grid);
			break;

		case 'd':
			SlideRight(grid);
			break;
		}
	}

	return 0;
}

void InitializeGrid(int grid[5][5])
{
	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			grid[x][y] = 0;
		}
	}
}

void DrawGrid(int grid[5][5])
{
	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			cout << grid[x][y] << " ";
		}
		cout << endl;
	}
}

void ClearScreen()
{
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
	system("cls");
#else
	system("clear");
#endif
}


void SlideUp(int grid[5][5])
{
	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			if (grid[x][y] != 0)
			{
				grid[x][0] = grid[x][y];
				grid[x][y] = 0;
			}
		}
	}
}

void SlideDown(int grid[5][5])
{
	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			if (grid[x][y] != 0)
			{
				grid[x][4] = grid[x][y];
				grid[x][y] = 0;
			}
		}
	}
}

void SlideLeft(int grid[5][5])
{
	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			if (grid[x][y] != 0)
			{
				grid[0][y] = grid[x][y];
				grid[x][y] = 0;
			}
		}
	}
}

void SlideRight(int grid[5][5])
{
	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			if (grid[x][y] != 0)
			{
				grid[4][y] = grid[x][y];
				grid[x][y] = 0;
			}
		}
	}
}
