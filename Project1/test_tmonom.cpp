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

TEST(TPolinom, stop)
{
	system("pause");
}