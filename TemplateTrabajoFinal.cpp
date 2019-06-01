#include<iostream>
#include<conio.h>
using namespace std;
using namespace System;
int algo[3][3] = { {1,0,1},{0,1,0},{1,0,1} };
void pintar(int x,int y) {
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (algo[i][j]) {
				Console::SetCursorPosition(x + j, y + i);
				cout << "*";
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
	int x=5, y=5,dx=1;
	int x1 = 20, y1 = 8, dx1 = -1;
	while (true)
	{
		borrar(x, y);
		if (x + dx < 0 || x + dx + 3 == 80)dx = -dx;
		x += dx;
		pintar(x, y);
		borrar(x1, y1);
		if (x1 + dx1 < 0 || x1 + dx1 + 3 == 80)dx1 = -dx1;
		x1 += dx1;
		pintar(x1, y1);
		_sleep(100);

	}
}