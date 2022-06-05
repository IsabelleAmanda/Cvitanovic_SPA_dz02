#include "game_of_life.h"
#include <iostream>
#include <ctime>
using namespace std;

bool game_of_life::slucajna_vrijednost()
{
	return rand() % (1 - 0 + 1) + 0; //-> generira random broj(0/1) u neku celiju kasnije
}

bool game_of_life::celija_zauzeta(int i, int j)
{
	return _generacija[i][j];
}

game_of_life::game_of_life()
{
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			_generacija[i][j] = slucajna_vrijednost();  //npr. na mjestu polje[1][2] ubaci broj 1
			_sljedeca_generacija[i][j] = _generacija[i][j];
		}
	}
}

void game_of_life::sljedeca_generacija()
{

	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			if (i == 0 || i == REDAKA - 1 || j == 0 || j == STUPACA - 1)
			{
				_sljedeca_generacija[i][j] = _generacija[i][j];
				break;
			}
			int suma = 0;
			suma += _generacija[i - 1][j];
			suma += _generacija[i - 1][j - 1];
			suma += _generacija[i][j - 1];
			suma += _generacija[i + 1][j - 1];
			suma += _generacija[i + 1][j];
			suma += _generacija[i + 1][j + 1];
			suma += _generacija[i][j + 1];
			suma += _generacija[i - 1][j + 1];
			if (celija_zauzeta(i, j) == true && (suma < 2 || suma>3))
			{
				_sljedeca_generacija[i][j] = false;
			}
			else if (celija_zauzeta(i, j) == true && suma == 3)
			{
				_sljedeca_generacija[i][j] = true;
			}
			else if (celija_zauzeta(i, j) == false && suma == 3)
			{
				_sljedeca_generacija[i][j] = _generacija[i][j];
			}
		}
	}
}

void game_of_life::iscrtaj()
{
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			if (_generacija[i][j] == 1)
			{
				cout << '*';
			}
			else
			{
				cout << '-';
			}
		}
		cout << endl;
	}
}
