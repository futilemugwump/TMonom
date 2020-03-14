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
	q.px = 1;
	q.py = 0;
	q.pz = 12;

	cout << "m = " << m << "\nq = " << q << endl;
	TPolinom m1, g1, res;
	res += m1;

	_getch();

	return 0;
}
