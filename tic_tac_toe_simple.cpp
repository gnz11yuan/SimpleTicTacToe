// tic_tac_toe_simple.cpp : Defines the entry point for the console application.
//
//#include <WinCon.h>
#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h> 

using namespace std;

int M[3][3], winner = 0, mef;

void initializare(int m[3][3]) {
	for (int i = 0; i <= 2; i++)
		for (int j = 0; j <= 2; j++)
		{
			m[i][j] = 1;
		}
}

void afisare(int m[3][3]) {

	cout << "\n\n";
	for (int i = 0; i <= 2; i++) {
		cout << "\t\t\t";
		for (int j = 0; j <= 2; j++)
			if (m[i][j] == 1) cout << char(223) << "\t\t";
			else if (m[i][j] == 3) cout << "X" << "\t\t";
			else cout << "0" << "\t\t";
		cout << "\n\n";
	}
}

void verificare_castig(int &winner) {
	for (int j = 0; j <= 2; j++)
	{
		if (M[j][0] * M[j][1] * M[j][2] == 27 || M[0][j] * M[1][j] * M[2][j] == 27)
			winner = 1;
		else if (M[j][0] * M[j][1] * M[j][2] == 125 || M[0][j] * M[1][j] * M[2][j] == 125)
			winner = 2;
	}
	if (M[0][0] * M[1][1] * M[2][2] == 27 || M[2][0] * M[1][1] * M[0][2] == 27)
		winner = 1;
	else if (M[0][0] * M[1][1] * M[2][2] == 125 || M[2][0] * M[1][1] * M[0][2] == 125)
		winner = 2;
}

void Verificare_blocare_mutare(int &mef) {

	mef = 0;

	for (int j = 0; j <= 2; j++)
	{
		if (M[j][0] * M[j][1] * M[j][2] == 9)
			if (M[j][0] == 1) {
				M[j][0] = 5;
				mef = 1;
				return;
			}
			else if (M[j][1] == 1) {
				M[j][1] = 5;
				mef = 1;
				return;
			}
			else {
				M[j][2] = 5;
				mef = 1;
				return;

			}
			if (M[0][j] * M[1][j] * M[2][j] == 9)
				if (M[0][j] == 1) {
					M[0][j] = 5;
					mef = 1;
					return;
				}
				else if (M[1][j] == 1) {
					M[1][j] = 5;
					mef = 1;
					return;
				}
				else {
					M[2][j] = 5;
					mef = 1;
					return;
				}
	}

	if (M[0][0] * M[1][1] * M[2][2] == 9)
		if (M[0][0] == 1) {
			M[0][0] = 5;
			mef = 1;
			return;
		}
		else if (M[1][1] == 1) {
			M[1][1] = 5;
			mef = 1;
			return;

		}
		else {
			M[2][2] = 5;
			mef = 1;
			return;
		}
	else if (M[2][0] * M[1][1] * M[0][2] == 9)
		if (M[2][0] == 1) {
			M[2][0] = 5;
			mef = 1;
			return;
		}
		else if (M[1][1] == 1) {
			M[1][1] = 5;
			mef = 1;
			return;
		}
		else {
			M[0][2] = 5;
			mef = 1;
			return;
		}

}

void randommove() {
	int ok=1, i, j;
	
	while (ok) {
		int i = rand() % 3;
		int j = rand() % 3;
		if (M[i][j] == 1) {
			M[i][j] = 5; 
			cout << "i=" << i << "   j=" << j;
			ok = 0;
		}
	}
}

int main()
{
	int i, j, k=0, mutare=1;	//k - mutare valida; mutare - ordine de mutare

	initializare(M);

	while (mutare<10) {
		afisare(M);
		if (mutare % 2) {
			k = 0;
			while (!k) {
				cout << "\n\n Your turn" << endl;

				cout << "\n\nx coordinate [0-2]:"; cin >> i;
				cout << "\ny coordinate [0-2]:"; cin >> j;
				if (M[i][j] != 1)
					cout << "\n\nILLEGAL MOVE\n";
				else {
					k = 1;
					M[i][j] = 3;
				}
			}
		}
		else {
			Verificare_blocare_mutare(mef);
			if (mef == 0)
				randommove();

			cout << "\n\n\nPlayer 2 turn complete";
		}
		verificare_castig(winner);

		system("cls");
		mutare++;

	}

	afisare(M);
	if (winner)
		cout << "\n\n\n\t\tWinner: Player " << winner;
	else cout << "\n\n\n\t\tDRAW";
	_getch();

	return 0;
}
