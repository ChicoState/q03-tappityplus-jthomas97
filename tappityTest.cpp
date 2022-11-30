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

TEST(tappityTest, reference_string)
{
	// TicTacToeBoard board = TicTacToeBoard();

	// Piece turn = board.toggleTurn();
	// ASSERT_EQ(turn, 'O');

	// Piece turn2 = board.toggleTurn();
	// ASSERT_EQ(turn2, 'X');

	tappity t = tappity();
}