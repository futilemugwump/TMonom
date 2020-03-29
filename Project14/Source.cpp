using namespace std;
#include "THeadList.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main() {
	TMonom m, q;

	m.coeff = 2;
	m.px = 4;
	m.py = 4;
	m.pz = 5;

	q.coeff = 3;
	q.px = 5;
	q.py = 4;
	q.pz = 3;

	//cout << "m = " << m << "\nq = " << q << endl;
	int monoms[3][2] = { {2, 145}, {3, 137}, {4, 145} };
	TPolinom p(monoms, 3);
	cout << p;
	int monoms2[3][2] = { {7, 145}, {8, 137}, {4, 145} };
	TPolinom p2(monoms2, 3);
	cout << p2 << endl;
	int monoms3[3][2] = { {2, 445}, {3, 436}, {4, 372} };
	TPolinom p3(monoms3, 3);
	p3 += p2;
	p3 *= 2;
	p3.InsInOrder(q);
	p3.AddMonom(m);
	p3 -= q;
	cout << p3;
	cout << p2;
	
	
	
	 
	
	/*int monoms[3][2] = { {2, 445}, {3, 436}, {4, 372} };
	TPolinom pol(monoms, 3);
	int monoms2[3][2] = { {2, 321}, {3, 122}, {4, 111} };
	TPolinom pol2(monoms2, 3);
	TPolinom res;
	pol -= m;
	cout << pol << endl; */
	//int monoms2[4][2] = { {5, 111}, {2, 145}, {3, 136}, {4, 372} };
	//TPolinom pol2(monoms2, 4);
	
	//p += p2;
	//cout << p;
	//TPolinom m1, g1, res;
	//res += m1;
	
	_getch();

	return 0;
}
