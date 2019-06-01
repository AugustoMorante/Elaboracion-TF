
#include<iostream>
#include<conio.h>
#include <stdio.h>
#include <windows.h>
constexpr auto ARRIBA = 72;
constexpr auto ABAJO = 80;
using namespace std;
using namespace System;

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
	for (int i = 30; i < 80; i = i + 2)
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
		ObtenerXY(25, i);
		cout << "|";
	}
	return;
}

int algo[3][3] = { { 1,0,1 },{ 0,1,0 },{ 1,0,1 } };
void pintar(int x, int y) {
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (algo[i][j]) {
				Console::SetCursorPosition(x + j, y + i);
				cout << "<";
			}
		}
	}
}
void borrar(int x, int y) {
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (algo[i][j]) {
				Console::SetCursorPosition(x + j, y + i);
				cout << " ";
			}
		}
	}
}
void main() {

	OcultarCursor();
	ParteFija();
	int x = 50, y = 4;
	ObtenerXY(x, y); cout << "|";
	int x1 = 30, y1 = 16, dx1 = 1;
	int x2 = 45, y2 = 8, dx2 = 1;
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

		borrar(x1, y1);
		if (x1 + dx1 < 26 || x1 + dx1 + 3 == 80)dx1 = -dx1;
		x1 += dx1;
		pintar(x1, y1);
		borrar(x2, y2);
		if (x2 + dx2 < 26 || x2 + dx2 + 3 == 80)dx2 = -dx2;
		x2 += dx2;
		pintar(x2, y2);

		_sleep(100);
	}

}
