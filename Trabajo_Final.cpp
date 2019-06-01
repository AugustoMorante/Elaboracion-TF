
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
constexpr auto ARRIBA = 72;
constexpr auto ABAJO = 80;
using namespace std;

void ObtenerXY(int x, int y)
{
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hCon, dwPos);
	return;
}

void OcultarCursor()
{
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO c;
	c.dwSize = 1;
	c.bVisible = FALSE;
	SetConsoleCursorInfo(hCon, &c);
	return;
}

void ParteFija()
{
	//MuellePlataforma
	for (int i = 0; i < 30; i++)
	{
		ObtenerXY(i, 6);
		cout << "=";
	}

	//MuelleParteInferiorMuelle
	for (int i = 0; i < 30; i = i + 2)
	{
		ObtenerXY(i, 7);
		cout << "/|";
	}

	//AguaLimite
	for (int i = 30; i < 100; i = i + 2)
	{
		ObtenerXY(i, 7);
		cout << " ~";
	}

	//CañaDiagonal
	for (int i = 5; i > 1; i--)
	{
		for (int j = 29; j < 36; j = j + 2)
		{
			if (i == 2 && j == 35 || i == 3 && j == 33 || i == 4 && j == 31 || i == 5 && j == 29)
			{
				ObtenerXY(j, i);
				cout << " /";
			}
		}
	}

	//CañaHorizontal
	for (int i = 38; i < 50; i++)
	{
		ObtenerXY(i, 1);
		cout << "_";
	}

	//CañaCuerdaFija
	for (int i = 2; i < 4; i++)
	{
		ObtenerXY(50, i);
		cout << "|";
	}

	//PescadorTorso
	for (int i = 4; i < 6; i++)
	{
		ObtenerXY(27, i);
		cout << "|";
	}

	//PescadorRodilla
	ObtenerXY(28, 5);
	cout << "/";

	//PescadorPierna
	ObtenerXY(29, 5);
	cout << "|";

	//PescadorCabeza
	ObtenerXY(27, 3);
	cout << "O";

	//PescadorBrazo
	ObtenerXY(28, 4);
	cout << "-";

	//MuelleSoporte
	for (int i = 8; i < 25; i++)
	{
		ObtenerXY(29, i);
		cout << "|";
	}
	return;
}

int main()
{
	OcultarCursor();
	ParteFija();
	int x = 50, y = 4;
	ObtenerXY(x, y); cout << "|";
	while (true)
	{
		
		if (_kbhit())
		{
			char tecla = _getch();
			if (tecla == ABAJO)
			{
				if (y > 22)
				{
					y--;
				}
				else
				{
					y++;
				}
			}
			if (y != 4)
			{
				ObtenerXY(x, y); cout << " ";
			}
			if (tecla == ARRIBA)
			{
				if (y < 5)
				{
					y++;
				}
				else
				{
					y--;
					ObtenerXY(50, 23); cout << " ";
				}
			}
			ObtenerXY(x, y); cout << "|";
		}
	}
	_getch();
}
