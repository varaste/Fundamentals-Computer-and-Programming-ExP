#include <iostream>
#include <string>
# include <cmath>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <time.h>
#include <cstdlib>
//11
using namespace std;
int main() {

	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE); //Color for text
	HANDLE hstdin = GetStdHandle(STD_INPUT_HANDLE); //Color for text

	int x = 1, y = 1, sx = 1, sy = 1, ex = 8, ey = 8, m, n, k;
	/*
	int a[10][10] = { 0,0,0,0,0,0,0,0,0,0,
	0,1,0,1,1,1,1,1,1,0,
	0,1,0,0,1,0,0,0,1,0,
	0,1,0,1,1,1,0,1,0,0,
	0,1,1,1,0,1,1,1,1,0,
	0,1,0,1,0,1,1,0,1,0,
	0,0,0,1,0,1,1,0,1,0,
	0,1,0,1,0,1,0,0,1,0,
	0,1,1,0,0,1,1,0,1,0,
	0,0,0,0,0,0,0,0,0,0 }, an[10][10] = {0};*/



	int a[10][10] = { 0 }, an[10][10] = { 0 };
	//be
	string answer;
	unsigned seed = time(NULL);
	srand(seed);
	m = x = sx = rand() % 2 + 1;
	n = y = sy = rand() % 2 + 1;
	while (m != 9 && n != 9) {
		a[m][n] = 1;
		k = rand() % 2;
		if (k == 0)
			m++;
		else
			n++;
	}
	ex = m;
	ey = n;
	/*
	for (int i = 0; i < 10; i++) {
	for (int j = 0; j < 10; j++) {
	cout << a[i][j]<<" ";
	}
	cout << endl;
	}
	*/
	a[sx][sy] = 2;
	an[sx][sy] = 2;

	while (x != ex && y != ey) {
		SetConsoleTextAttribute(hstdout, 0x09); //Color for text
		cout << "what direction you want to go\n";
		cin >> answer;
		if (answer == "d" && (a[x + 1][y] == 1 || a[x + 1][y] == 2)) {
			if (a[x + 1][y] == 2) {
				a[x][y] = 1;
				an[x][y] = 0;
			}
			an[x + 1][y] = 2;
			a[x + 1][y] = 2;

			x++;
		}
		else if (answer == "d" && a[x + 1][y] == 0 && x + 1 != 9 && x + 1 != 0 && y != 0 && y != 9) {
			a[x + 1][y] = 4;
			an[x + 1][y] = 4;
		}
		if (answer == "u" && (a[x - 1][y] == 1 || a[x - 1][y] == 2)) {
			if (a[x - 1][y] == 2) {
				a[x][y] = 1;
				an[x][y] = 0;
			}
			an[x - 1][y] = 2;
			a[x - 1][y] = 2;

			x--;
		}
		else if (answer == "u" && a[x - 1][y] == 0 && x != 9 && x - 1 != 0 && y != 0 && y != 9) {
			a[x - 1][y] = 4;
			an[x - 1][y] = 4;
		}
		if (answer == "r" && (a[x][y + 1] == 1 || a[x][y + 1] == 2)) {
			if (a[x][y + 1] == 2) {
				a[x][y] = 1;
				an[x][y] = 0;
			}
			an[x][y + 1] = 2;
			a[x][y + 1] = 2;

			y++;
		}
		else if (answer == "r" && a[x][y + 1] == 0 && x != 9 && x != 0 && y != 0 && y + 1 != 9) {
			a[x][y + 1] = 4;
			an[x][y + 1] = 4;
		}
		if (answer == "l" && (a[x][y - 1] == 1 || a[x][y - 1] == 2)) {
			if (a[x][y - 1] == 2) {
				a[x][y] = 1;
				an[x][y] = 0;
			}
			an[x][y - 1] = 2;
			a[x][y - 1] = 2;

			y--;
		}
		else if (answer == "l" && a[x][y - 1] == 0 && x != 9 && x != 0 && y - 1 != 0 && y != 9) {
			a[x][y - 1] = 4;
			an[x][y - 1] = 4;
		}
		system("cls");

		cout << endl;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (i == 9 || i == 0 || j == 0 || j == 9) {
					SetConsoleTextAttribute(hstdout, 0x0e); //Color for text
					cout << char(219) << char(219);
				}



				if (an[i][j] == 0 && i != 9 && i != 0 && j != 0 && j != 9) {
					SetConsoleTextAttribute(hstdout, 0x0f); //Color for text
					cout << char(219) << char(219);
				}
				if (an[i][j] == 2) {
					SetConsoleTextAttribute(hstdout, 0x0a); //Color for text
					cout << char(219);
					SetConsoleTextAttribute(hstdout, 0x0a); //Color for text
					cout << char(219);
				}
				if (an[i][j] == 4) {
					SetConsoleTextAttribute(hstdout, 0x0c); //Color for text
					cout << char(219);
					SetConsoleTextAttribute(hstdout, 0x0c); //Color for text
					cout << char(219);
				}
			}

			cout << endl;
		}
		cout << endl;
	}
	cout << "shoma bordid\n";
	system("pause");
}
