#include <iostream>
#include <conio.h>
#include <windows.h>
bool gameOver;
const int height = 20;
const int width = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int numberOfTail=0;
enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direction dir;
void setup()
{
	score = 0;
	numberOfTail = 0;
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}
void draw()
{
	system("cls");
	for (int i = 0; i < width ; i++)
	{
		std::cout << "#";
	}
	std::cout << std::endl;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
			{
				std::cout << "#";
		    }
			else if (j == width - 1)
			{
				std::cout << "#";
			}
			
			else if (i==y && j == x)
			{
				std::cout << "O";
			}
			else if (i == fruitY && j == fruitX)
			{
				std::cout << "*";
			}
			else
			{   
				bool printed = false;
				for (int k = 0; k < numberOfTail; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						std::cout << "o";
						printed = true;
					}
				}
				if (!printed)
				{
					std::cout << " ";
				}
			}
			
		}
		std::cout << std::endl;
	}
	for (int i = 0; i < width ; i++)
	{
		std::cout << "#";
	}
	std::cout << std::endl;
	std::cout << "score: " << score << std::endl;
}
void input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'w':
		 dir = UP;
		 break;
		case 's':
		 dir = DOWN;
		 break;
		case 'a':
	     dir = LEFT;
		 break;
		case 'd':
		 dir = RIGHT;
		 break;	
		}
	}
}
void logic()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	tailX[0] = x;
	tailY[0] = y;
	int prev2X, prev2Y;
	for (int i = 1; i < numberOfTail; i++)
	{
		
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
		
 	}
	
	switch (dir)
	{
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	}
	for (int i = 0; i < numberOfTail; i++)
		if (tailX[i] == x && tailY[i] == y)
			gameOver = true;

	if ((x>width-2||x<1) || (y>height-1 || y<0))
	{
		gameOver = true;
	}
	if ((x == fruitX) && (y == fruitY))
	{
		score+=5;
		fruitX = rand() % width;
		fruitY = rand() % height;
		numberOfTail++;
	}
}
int main()
{   
	char choice;
	a:
	setup();
	while (gameOver!=true)
		{
			draw();
			input();
			logic();
			Sleep(80);
	    }
	std::cout << "Your final score is " << score << std::endl;
	b:
	std::cout << "Would you like to play again?\nA)Yes\nB)No\n";
	std::cin >> choice;
	if ((choice == 'a') || (choice == 'A'))
	{
		goto a;
	}
	else if ((choice == 'b') || (choice == 'B'))
	{
		std::cout << "Goodbye!\n";
	}
	else
	{
		std::cout << "Invalid input, please try again.\n";
	}
	return 0;
}