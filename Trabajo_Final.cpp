
#include "pch.h"
#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
using namespace std;

int main()
{
	system("color 3F");
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 27; j++)
		{
			if (i == 8 && j <= 5 || i == 3 && j >= 10 && j <= 13)
			{
				cout << "-";
			}
			else
			{
				cout << " ";
			}
			if (i == 9 && j > 5)
			{
				cout << "~";
			}
			if (j == 5 && i >= 8 || j == 12 && i > 3 && i <= 6 || i == 7 && j == 2 || i == 7 && j == 0 || i == 6 && j == 1 || i == 5 && j == 1)
			{
				cout << "|";
			}
			else
			{
				cout << " ";
			}
			if (i == 4 && j == 7 || i == 5 && j == 6 || i == 6 && j == 5 || i == 7 && j == 4)
			{
				cout << "/";
			}
			if (i == 4 && j == 1)
			{
				cout << "O";
			}
			if (i == 15 && j == 13) 
			{
				cout << "<";
			}
			if (i == 15 && j == 15 || i == 15 && j == 12)
			{
				cout << ">";
			}
			if (i == 15 && j == 14)
			{
				cout << "O";
			}
		}
		cout << endl;
	}
	_getch();
	return 0;
}
