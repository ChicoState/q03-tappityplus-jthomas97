/**
 * Unit Test suite
**/

#include <gtest/gtest.h>
#include "tappity.h"
 
class tappityTest : public ::testing::Test
{
	protected:
		tappityTest(){} 
		virtual ~tappityTest(){} 
		virtual void SetUp(){}
		virtual void TearDown(){}
};

//######################################################
//############# TEST FOR length_difference #############
//######################################################
TEST(tappityTest, entry_same_length)
{
	tappity t = tappity("Hello");
	t.entry("Hello");
	int len = t.length_difference();

	ASSERT_EQ(len, 0);
}

TEST(tappityTest, entry_reference_longer)
{
	tappity t = tappity("Hello");
	t.entry("Hi");
	int len = t.length_difference();

	ASSERT_EQ(len, 3);
}

TEST(tappityTest, entry_reference_shorter)
{
	tappity t = tappity("Hi");
	t.entry("Hello");
	int len = t.length_difference();

	ASSERT_EQ(len, 3);
}

TEST(tappityTest, entry_blank_input)
{
	tappity t = tappity("Hi");
	int len = t.length_difference();

	ASSERT_EQ(len, 2);
}

//#############################################
//############# TEST FOR accuracy #############
//#############################################

TEST(tappityTest, accuracy_same_string)
{
	tappity t = tappity("Hi");
	t.entry("Hi");

	double a = t.accuracy();

	ASSERT_EQ(a, 100.0);
}

TEST(tappityTest, accuracy_reference_longer)
{
	tappity t = tappity("himynameisjudeee");
	t.entry("himyname");

	double a = t.accuracy();

	ASSERT_EQ(a, 50.0);
}

TEST(tappityTest, accuracy_input_longer)
{
	tappity t = tappity("himyname");
	t.entry("himynameisjudeee");

	double a = t.accuracy();

	ASSERT_EQ(a, 50.0);
}

TEST(tappityTest, accuracy_default_input)
{
	tappity t = tappity("himyname");

	double a = t.accuracy();

	ASSERT_EQ(a, 0.0);
}

TEST(tappityTest, accuracy_max_limit)
{
	tappity t = tappity("himyname");

	double a = t.accuracy();

	ASSERT_LE(a, 100.0);
}

TEST(tappityTest, accuracy_min_limit)
{
	tappity t = tappity("himyname");

	double a = t.accuracy();

	ASSERT_GE(a, 0.0);
}

