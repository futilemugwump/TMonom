using namespace std;
#include "THeadList.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main() {
	TMonom m, q;

	m.coeff = 15;
	m.px = 5;
	m.py = 4;
	m.pz = 3;

	q.coeff = 3;
	q.px = 5;
	q.py = 4;
	q.pz = 3;

	cout << "m = " << m << "\nq = " << q << endl;
	int monoms[3][2] = { {2, 145}, {3, 137}, {4, 145} };
	TPolinom p(monoms, 2);
	cout << p;
	//TPolinom m1, g1, res;
	//res += m1;

	_getch();

	return 0;
}
