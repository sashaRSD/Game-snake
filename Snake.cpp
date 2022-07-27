#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <locale.h>
#include <stdio.h>

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE hStdout;
COORD coord; COORD coord2; COORD coord3;
FILE *creat, *vvod, *read;
const int widht = 40;
const int height = 20;
int igr = 0;
int str;
int q, w, e, r, t;
int x, y, xx, yy, Fx, Fy, score, score2, total;
int tX[1000], tY[1000], p2X, p2Y, pX, pY;
enum variant { STOP, LEFT, RIGHT, UP, DOWN, PAUSE };
variant vib; variant vib2;
char upr[100] = { " Стрелка вверх - up" };
char upr2[100] = { " Стрелка вниз - down" };
char upr3[100] = { " Стрелка влево - left" };
char upr4[100] = { " Стрелка вправо - right" };
char upr5[100] = { " SPACE - Пауза" };
char upr6[100] = { " ESC - Выход" };

void Rand()
{
	Fx = rand() % widht;
	Fy = rand() % height;
	if (Fx == 0 || Fy == 0)
		Rand();

	for (int i = 0; i <= total; i++)
		if (tX[i] == Fx && tY[i] == Fy)
			Rand();
}


void Vich()
{

	int igr = 1;
	vib = STOP;
	vib2 = PAUSE;
	x = widht / 2;
	y = height / 2;
	Rand();
	t = 0;
	total = 0;
	score = 0;
}

void Draw3(COORD coord3)
{
	int y2;
	for (y2 = 0; y2 <= height; y2++)
	{
		coord3.X = widht + 1;
		coord3.Y = y2;
		SetConsoleCursorPosition(hStdout, coord3);

		if (y2 == 1)
		{
			SetConsoleTextAttribute(hConsole, (WORD)((7 << 4) | 0));
			puts("  Управление:");
		}

		if (y2 == 2)
		{
			SetConsoleTextAttribute(hConsole, (WORD)((7 << 4) | 0));
			puts(upr);
		}

		if (y2 == 3)
		{
			SetConsoleTextAttribute(hConsole, (WORD)((7 << 4) | 0));
			puts(upr2);
		}
		if (y2 == 4)
		{
			SetConsoleTextAttribute(hConsole, (WORD)((7 << 4) | 0));
			puts(upr3);
		}

		if (y2 == 5)
		{
			SetConsoleTextAttribute(hConsole, (WORD)((7 << 4) | 0));
			puts(upr4);
		}

		if (y2 == 6)
		{
			SetConsoleTextAttribute(hConsole, (WORD)((7 << 4) | 0));
			puts(upr5);
		}

		if (y2 == 7)
		{
			SetConsoleTextAttribute(hConsole, (WORD)((7 << 4) | 0));
			puts(upr6);
		}


		if (y2 == height - 1)
		{
			SetConsoleTextAttribute(hConsole, (WORD)((7 << 4) | 0));
			puts("  ТМ SashaGaming22");
		}


		if (y2 == height - 2 || y2 == 0 || y2 == 8 || y2 == height)
		{
			SetConsoleTextAttribute(hConsole, (WORD)((7 << 4) | 0));
			puts(" ----------------------");
		}

		if (y2 > 8 && y2 < 18)
		{
			SetConsoleTextAttribute(hConsole, (WORD)((7 << 4) | 0));
			puts(" ");
		}

	}
}


void Draw2(COORD coord)
{

	SetConsoleCursorPosition(hStdout, coord);
	if (xx == 0 || xx == widht || yy == 0 || yy == height)
	{
		SetConsoleTextAttribute(hConsole, (WORD)((6 << 4) | 0));
		_putch('#');
	}

	if (xx == widht && yy == height)
	{
		SetConsoleTextAttribute(hConsole, (WORD)((7 << 4) | 0));
		printf("\n\n Счёт: %d", score);

		printf(" Рекорд:");
		fopen_s(&read, "c:/game/Snake/record.txt", "r");
		fscanf_s(read, "%d", &score2);
		printf_s(" %d", score2);
		fclose(read);


		printf(" \n\n\n\n\n\n\n ");

	}
}

void Draw(COORD coord)
{
	SetConsoleCursorPosition(hStdout, coord);

	if (xx == x && yy == y)
	{
		SetConsoleTextAttribute(hConsole, (WORD)((6 << 4) | 2));
		_putch('0');
	}

	if (xx == Fx && yy == Fy)
	{
		SetConsoleTextAttribute(hConsole, (WORD)((6 << 4) | 4));
		_putch('F');
	}

	for (int k = 0; k < total; k++)
		if (tX[k] == xx && tY[k] == yy)
		{
			SetConsoleTextAttribute(hConsole, (WORD)((6 << 4) | 10));
			if (xx == tX[total - 1] && yy == tY[total - 1])
			{
				SetConsoleTextAttribute(hConsole, (WORD)((6 << 4) | 2));
				_putch('#');
			}
			else _putch('o');
		}

	if (xx >= 1 && xx < widht && yy >= 1 && yy < height)
	{
		SetConsoleTextAttribute(hConsole, (WORD)((6 << 4) | 6));
		_putch(' ');
	}

}

void DCoord()
{

	for (xx = 0; xx <= widht; xx++)
		for (yy = 0; yy <= height; yy++)
		{
			coord.X = xx;
			coord.Y = yy;
			Draw(coord);
			Draw2(coord);
		}

	if (t == 0)
	{
		Draw3(coord3);
		t = 1;
	}

	if (w == 2)
	{
		Sleep(15);
	}

	if (w == 1)
	{
		Sleep(30);
	}

}

void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 75: if (total >= 2)
		{
			if (vib2 != RIGHT)
			{
				if (vib != RIGHT)
				{
					vib = LEFT; vib2 = vib; break;
				}
			}
			else break;
		}
				 else vib = LEFT; vib2 = vib; break;
		case 77:  if (total >= 2)
		{
			if (vib2 != LEFT)
			{
				if (vib != LEFT)
				{
					vib = RIGHT; vib2 = vib; break;
				}
			}
			else break;
		}
				  else vib = RIGHT; vib2 = vib; break;

		case 72: if (total >= 2)
		{
			if (vib2 != DOWN)
			{
				if (vib != DOWN)
				{
					vib = UP; vib2 = vib; break;
				}
			}
			else break;
		}
				 else vib = UP; vib2 = vib; break;

		case 80: if (total >= 2)
		{
			if (vib2 != UP)
			{
				if (vib != UP)
				{
					vib = DOWN; vib2 = vib; break;
				}
			}
			else break;
		}
				 else vib = DOWN; vib2 = vib; break;

		case 32: vib = STOP; break;
		case 27: igr = 1; break;
		}
	}

	if (_kbhit())
	{
		switch (_getch())
		{
		case 75: if (total >= 2)
		{
			if (vib2 != RIGHT)
			{
				if (vib != RIGHT)
				{
					vib = LEFT; vib2 = vib; break;
				}
			}
			else break;
		}
				 else vib = LEFT; vib2 = vib; break;
		case 77:  if (total >= 2)
		{
			if (vib2 != LEFT)
			{
				if (vib != LEFT)
				{
					vib = RIGHT; vib2 = vib; break;
				}
			}
			else break;
		}
				  else vib = RIGHT; vib2 = vib; break;

		case 72: if (total >= 2)
		{
			if (vib2 != DOWN)
			{
				if (vib != DOWN)
				{
					vib = UP; vib2 = vib; break;
				}
			}
			else break;
		}
				 else vib = UP; vib2 = vib; break;

		case 80: if (total >= 2)
		{
			if (vib2 != UP)
			{
				if (vib != UP)
				{
					vib = DOWN; vib2 = vib; break;
				}
			}
			else break;
		}
				 else vib = DOWN; vib2 = vib; break;

		case 32: vib = STOP; break;
		case 27: igr = 1; break;
		}
	}
}

void VichXv()
{
	if (vib != STOP)
	{
		pX = tX[0];
		pY = tY[0];
		tX[0] = x;
		tY[0] = y;
	}

	for (int i = 1; i <= total; i++)
	{
		if (vib != STOP)
		{

			p2X = tX[i];
			p2Y = tY[i];
			tX[i] = pX;
			tY[i] = pY;
			pX = p2X;
			pY = p2Y;
		}
		else
		{
			int xxx = tX[total], yyy = tY[total];
			coord2.X = xxx;
			coord2.Y = yyy;
			SetConsoleCursorPosition(hStdout, coord2);
		}
	}
}

void VichIgr()
{
	if (q == 1)
	{
		if (x <= 0 || x >= widht || y <= 0 || y >= height)
			igr = 3;
	}

	if (q == 2)
	{
		if (x >= widht || x <= 0)
			if (x >= widht)
				x = 1;
			else if (x <= 0)
				x = widht - 1;

		if (y >= height || y <= 0)
			if (y >= height)
				y = 1;
			else if (y <= 0)
				y = height - 1;
	}

	for (int i = 0; i < total; i++)
	{
		if (tX[i] == x && tY[i] == y)
		{
			if (vib != STOP)
				igr = 2;
		}
	}

	if (x == Fx && y == Fy)
	{
		if (r == 1)
		{
			printf("\a");
		}
		score++;
		total++;
		Rand();
	}
}

void Logic()
{
	VichXv();

	switch (vib)
	{
	case LEFT: x--; break;
	case RIGHT: x++; break;
	case UP: y--; break;
	case DOWN: y++; break;
	case STOP:  break;
	}

	VichIgr();

}


void nastr()
{
	printf(" Выберите режим? \n");
	printf("1-Classic \n");
	printf("2-Endless \n");
	printf(" Ваш выбор: ");
	scanf_s("%d", &q);
	if (q != 1 && q != 2)
	{
		system("cls");
		printf(" Этот вариант отсутвует! Повторите ввод!!! \n\n");
		nastr();
	}
}

void nastr2()
{
	printf("\n Уровень сложности: \n");
	printf("1-Легко \n");
	printf("2-Средне \n");
	printf("3-Сложно \n");
	printf(" Ваш выбор: ");
	scanf_s("%d", &w);
	if (w != 1 && w != 2 && w != 3)
	{
		printf("\n Этот вариант отсутвует! Повторите ввод!!! \n\n");
		nastr2();
	}
}

void nastr3()
{
	printf("\n Включить звук? \n");
	printf("1-да \n");
	printf("2-нет \n");
	printf(" Ваш выбор: ");
	scanf_s("%d", &r);
	if (r != 1 && r != 2)
	{
		printf("\n Этот вариант отсутвует! Повторите ввод!!! \n\n");
		nastr3();
	}
	system("cls");
}

void okon()
{

	if (igr == 1)
	{
		Draw3(coord3);
		printf("\n\n Вы завершили игру!!!\n");
	}

	if (igr == 2)
	{
		Draw3(coord3);
		printf("\n\n Змея врезелась в себя! Вы проиграли!!!\n");
	}

	if (igr == 3)
	{
		Draw3(coord3);
		printf("\n\n Змея врезелась в стенку! Вы проиграли!!!\n");
	}
}


void menu()
{

	DWORD dwAttr1 = ::GetFileAttributesW(L"C:\\game\\Snake\\record.txt");
	if (0xffffffff == dwAttr1)
	{
		CreateDirectoryW(L"C:\\game", NULL);
		CreateDirectoryW(L"C:\\game\\Snake", NULL);
		fopen_s(&creat, "c:/game/Snake/record.txt", "w");
		fclose(creat);
	}

	fopen_s(&read, "c:/game/Snake/record.txt", "r");
	fscanf_s(read, "%d", &score2);
	fclose(read);
	printf("  Настройки: \n\n");
	nastr();
	nastr2();
	nastr3();
	Vich();
	while (igr == 0)
	{
		DCoord();
		Input();
		Logic();
	}
	okon();

	if (score2 <= score)
	{
		fopen_s(&creat, "c:/game/Snake/record.txt", "w");
		fclose(creat);
		fopen_s(&vvod, "c:/game/Snake/record.txt", "a");
		fprintf(vvod, "%d", score);
		fclose(vvod);
	}
}

void povt()
{
	printf("\n Попробовать еще раз? \n");
	printf("1-да \n");
	printf("2-нет \n");
	printf(" Ваш выбор: ");
	scanf_s("%d", &e);
	if (e != 1 && e != 2)
	{
		system("cls");
		printf(" Этот вариант отсутвует! Повторите ввод!!! \n\n");
		povt();
	}

	if (e == 1)
	{
		system("cls");
		igr = 0;
		for (int i = 1; i < total; i++)
		{
			tX[i] = 0;
			tY[i] = 0;
		}

		menu();
		povt();
	}
	else printf("\r Нажмите любую клавишу, чтобы выйти из игры!");

}

void SetWindow(int Width2, int Height2)
{
	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height2 - 1;
	Rect.Right = Width2 - 1;

	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleWindowInfo(Handle, TRUE, &Rect);
}

void SetWindow2(int Width3, int Height3)
{
	_COORD coord;
	coord.X = Width3;
	coord.Y = Height3;

	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleScreenBufferSize(Handle, coord);
}

int main()
{
	system("color 70");
	setlocale(LC_ALL, "RUS");
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetWindow(70, 30);
	SetWindow2(70, 30);
	Vich();
	menu();
	povt();
	_getch();
	return 0;
}