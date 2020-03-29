#include "gtest.h"
#include "..//Project14/TheadList.h"


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
TEST(TPolinom, can_create_copied_polynom)
{
	int monoms[3][2] = { {2, 145}, {3, 137}, {4, 145} };
	TPolinom pol(monoms, 3);
	
	
	ASSERT_NO_THROW(TPolinom pol1(pol));
}
TEST(TPolinom, can_add_monom)
{
	int monoms[3][2] = { {2, 145}, {3, 137}, {4, 145} };
	TPolinom pol(monoms, 3);
	TMonom w;
	w.coeff = 5;
	w.px = 1;
	w.py = 1;
	w.pz = 1;
	ASSERT_NO_THROW(pol.AddMonom(w));
}

TEST(TPolinom, can_multiplicate_pol_and_mon) {
	int monoms[3][2] = { {2, 145}, {3, 136}, {4, 372} };
	TPolinom pol(monoms, 3);
	TMonom c;
	c.coeff = 6;
	c.px = 1;
	c.py = 2;
	c.pz = 3;
	ASSERT_NO_THROW(pol *= c);
	int monoms2[3][2] = { {12, 268}, {18, 259}, {24, 495} };
	TPolinom pol2(monoms2, 3);
	EXPECT_EQ((pol == pol2),1);
} 
TEST(TPolinom, copied_polynomial_is_equal_to_original)
{
	int monoms[3][2] = { {2, 145}, {3, 137}, {4, 145} };
	TPolinom pol(monoms, 3);
	TPolinom pol1(pol);
	EXPECT_EQ(pol1, pol);
}
 TEST(TPolinom, can_add_pol_and_pol) {
	 int monoms[3][2] = { {2, 545}, {3, 536}, {4, 372} };
	 TPolinom pol(monoms, 3);
	 int monoms2[3][2] = { {5, 545}, {1, 536}, {4, 478} };
	 TPolinom pol2(monoms2, 3);
	 pol += pol2;
	 int monoms3[4][2] = {{7, 545}, {4, 536}, {4, 478}, {4, 372}, };
	 TPolinom res(monoms3, 4);
	
	EXPECT_TRUE((res == pol), 1);
}

TEST(TPolinom, can_multiplicate_pol_and_scal) {
	int monoms[3][2] = { {2, 145}, {3, 136}, {4, 372} };
	TPolinom pol(monoms, 3);
	pol *= 3;
	int monoms2[3][2] = { {6, 145}, {9, 136}, {12, 372} };
	TPolinom pol2(monoms2, 3);
	EXPECT_TRUE(pol == pol2);
}
TEST(TPolinom, if_InsInOrder_works_or_not) {
	int monoms[3][2] = { {2, 445}, {3, 436}, {4, 372} };
	TPolinom pol(monoms, 3);
	TMonom w;
	w.coeff = 5;
	w.px = 1;
	w.py = 1;
	w.pz = 1;
	pol.InsInOrder(w);
	int monoms2[4][2] = { {2, 445}, {3, 436}, {4, 372}, {5, 111} };
	TPolinom pol2(monoms2, 4);
	EXPECT_TRUE(pol == pol2);
}

TEST(TPolinom, can_multiply_by_polynomial)
{
	int monoms[3][2] = { {2, 445}, {3, 436}, {4, 372} };
	TPolinom pol(monoms, 3);
	int monoms2[3][2] = { {2, 321}, {3, 122}, {4, 111} };
	TPolinom pol2(monoms2, 3);
	TPolinom res;
	res = pol * pol2;
	int monoms3[12][2] = { {4, 766}, {6, 757}, {8, 693}, {6, 567}, {9, 558}, {8, 556},{6, 757}, {9, 558}, {12, 547}, {8, 693}, {12, 494}, {16, 483} };
	TPolinom ressq(monoms3, 12);
	EXPECT_TRUE(res == ressq);
}

TEST(TPolinom, can_subtract)
{
	TMonom m, q;

	m.coeff = 2;
	m.px = 4;
	m.py = 4;
	m.pz = 5;
	int monoms[3][2] = { {2, 445}, {3, 436}, {4, 372} };
	TPolinom pol(monoms, 3);
	pol -= m;
	int monoms2[2][2] = { {3, 436}, {4, 372} };
	TPolinom res(monoms2, 2);


	EXPECT_TRUE(res == pol);
}

TEST(TPolinom, stop)
{
	system("pause");
}