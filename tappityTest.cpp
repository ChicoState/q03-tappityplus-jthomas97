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