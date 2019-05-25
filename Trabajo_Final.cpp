
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
			if (i == 10 && j <= 5)
			{
				cout << "-";
			}
			else
			{
				cout << " ";
			}
			if (i == 13 && j > 5)
			{
				cout << "~";
			}
			else
			{
				cout << " ";
			}
			if (j == 5 && i >= 10)
			{
				cout << "|";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}
	_getch();
    return 0;
}

