#include "gtest.h"
#include "..//Project14/TheadList.h"
#include <string>

TEST(TMonom, can_create_monom)
{
	
	ASSERT_NO_THROW(TMonom C);
	
}
TEST(TMonom, can_ins_monom_with_pos_coeff)
{
	TMonom monom;
	monom.px = 0;
	monom.py = 0;
	monom.pz = 0;
	ASSERT_NO_THROW(monom.coeff = 1);
}

TEST(TMonom, can_ins_monom_with_neg_coeff)
{
	TMonom monom;
	monom.px = 0;
	monom.py = 0;
	monom.pz = 0;
	ASSERT_NO_THROW(monom.coeff = -1);
}

TEST(TMonom, can_ins_monom_with_positive_step)
{
	TMonom monom;
	monom.px = 1;
	monom.py = 1;
	monom.pz = 1;
	ASSERT_NO_THROW(monom.coeff = 15);
}

TEST(TMonom, can_ins_monom_with_negative_step)
{
	TMonom monom;
	monom.px = -1;
	monom.py = -1;
	monom.pz = -1;
	ASSERT_NO_THROW(monom.coeff = -15);
}

TEST(TMonom, can_compare_equal_monoms)
{
	TMonom monom1, monom2;
	monom1.coeff = 5;
	monom1.px = 1;
	monom1.py = 1;
	monom1.pz = 1;
	monom2.coeff = 4;
	monom2.px = 1;
	monom2.py = 1;
	monom2.pz = 1;
	EXPECT_EQ(monom1 == monom2, 1);
}

TEST(TMonom, can_compare_monoms_that_are_not_equal)
{
	TMonom monom1, monom2;
	monom1.coeff = 5;
	monom1.px = 1;
	monom1.py = 1;
	monom1.pz = 0;
	monom2.coeff = 4;
	monom2.px = 1;
	monom2.py = 2;
	monom2.pz = 3;
	EXPECT_EQ(monom1 != monom2, 1);
}

TEST(TMonom, can_compare_monoms)
{
	TMonom monom1, monom2;
	monom1.coeff = 5;
	monom1.px = 1;
	monom1.py = 1;
	monom1.pz = 0;
	monom2.coeff = 4;
	monom2.px = 1;
	monom2.py = 2;
	monom2.pz = 3;
	EXPECT_EQ(monom1 < monom2, 1);
	EXPECT_EQ(monom1 > monom2, 0);
}
TEST(TPolinom, can_create_polynom)
{
	ASSERT_NO_THROW(TPolinom bf);
}
TEST(TPolinom, can_create_polynom_from_the_array)
{
	int monoms[3][2] = { {2, 145}, {3, 137}, {4, 145} };
	ASSERT_NO_THROW(TPolinom p(monoms, 2));
}
TEST(TPolinom, can_add_monom)
{
	TPolinom p, resq;
	TMonom a, w, res;
	a.coeff = 1;
	a.px = 1;
	a.py = 1;
	a.pz = 1;
	w.coeff = 5;
	w.px = 1;
	w.py = 1;
	w.pz = 1;
	res.coeff = 6;
	w.px = 1;
	w.py = 1;
	w.pz = 1;
	resq.InsInOrder(res);
	ASSERT_NO_THROW(p.InsInOrder(a));
	//EXPECT_EQ(res, (a + w));
	ASSERT_NO_THROW(p + w);
	//EXPECT_EQ((resq == p), 1);
	ASSERT_NO_THROW(a + w);
	
}

TEST(TPolinom, can_multiplicate_pol_and_mon) {
	TMonom m, n, c;
	m.coeff = 5;
	m.px = 1;
	m.py = 1;
	m.pz = 0;
	n.coeff = 7;
	n.px = 1;
	n.py = 2;
	n.pz = 3;
	TPolinom p;
	p.InsInOrder(m);
	p = p*n;
	TMonom res;
	res.coeff = 35;
	res.px = 2;
	res.py = 3;
	res.pz = 3;
	TPolinom q;
	q.InsInOrder(res);
	EXPECT_EQ((q == p),1);
}

/*TEST(TPolinom, can_add_pol_and_pol) {
	TMonom m, n, c;
	m.coeff = 5;
	m.px = 1;
	m.py = 1;
	m.pz = 0;
	n.coeff = 7;
	n.px = 1;
	n.py = 2;
	n.pz = 3;
	c.coeff = 35;
	c.px = 2;
	c.py = 3;
	c.pz = 3;
	TPolinom p, l, res;
	p.insOrd(m);
	l.insOrd(n);
	res.insOrd(c);
	EXPECT_TRUE(res == p * l);
}

TEST(TPolinom, can_multiplicate_pol_and_scal) {
	TMonom m, n;
	m.coeff = 5;
	m.px = 1;
	m.py = 1;
	m.pz = 0;
	n.coeff = 30;
	n.px = 1;
	n.py = 1;
	n.pz = 0;
	TPolinom p, res;
	p.insOrd(m);
	p.insOrd(m);
	p *= 3;
	res.insOrd(m);
	EXPECT_TRUE(res == p);
}
*/


TEST(TPolinom, stop)
{
	system("pause");
}