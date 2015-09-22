/**
 * Unit Tests for Rando Test
**/

#include <gtest/gtest.h>
#include "rando.h"

/*  
	FUNCTIONS WE NEED TO TEST:

	bool shouldWorry(bool,bool,bool);
	bool isDivisbleBy(int,int);
	bool isPrime(int);
	int nearestToZero(int,int);
*/
 
class RandoTest : public ::testing::Test
{
	protected:
		RandoTest(){} //constructor runs before each test
		virtual ~RandoTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(RandoTest, allChildrenSmile)
{
	Rando rando;
	ASSERT_TRUE( rando.shouldWorry(true,true,true) );
}

TEST(RandoTest, oneChildSmiles)
{
	Rando rando;
	ASSERT_TRUE( rando.shouldWorry(true,false,false) );
	ASSERT_TRUE( rando.shouldWorry(false,true,false) );
	ASSERT_TRUE( rando.shouldWorry(false,false,true) );
}
  
TEST(RandoTest, twoChildrenSmile)
{
	Rando rando;
	ASSERT_FALSE( rando.shouldWorry(true,true,false) );
	ASSERT_FALSE( rando.shouldWorry(true,false,true) );
	ASSERT_FALSE( rando.shouldWorry(false,true,true) );
}

TEST(RandoTest, noChildrenSmile)
{
	Rando rando;
	ASSERT_FALSE( rando.shouldWorry(false,false,false) );
}
