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

TEST(RandoTest, isDivisible)
{
	Rando rando;
	ASSERT_TRUE( rando.isDivisibleBy(1,2) );
	ASSERT_TRUE( rando.isDivisibleBy(2,2) );
	ASSERT_TRUE( rando.isDivisibleBy(2,1) );
	ASSERT_TRUE( rando.isDivisibleBy(262144,512) );
	ASSERT_TRUE( rando.isDivisibleBy(262144,262144) );
	ASSERT_TRUE( rando.isDivisibleBy(512,262144) );

	ASSERT_TRUE( rando.isDivisibleBy(-1,2) );
	ASSERT_TRUE( rando.isDivisibleBy(-2,2) );
	ASSERT_TRUE( rando.isDivisibleBy(-2,1) );
	ASSERT_TRUE( rando.isDivisibleBy(-262144,512) );
	ASSERT_TRUE( rando.isDivisibleBy(-262144,262144) );
	ASSERT_TRUE( rando.isDivisibleBy(-512,262144) );

	ASSERT_TRUE( rando.isDivisibleBy(1,-2) );
	ASSERT_TRUE( rando.isDivisibleBy(2,-2) );
	ASSERT_TRUE( rando.isDivisibleBy(2,-1) );
	ASSERT_TRUE( rando.isDivisibleBy(262144,-512) );
	ASSERT_TRUE( rando.isDivisibleBy(262144,-262144) );
	ASSERT_TRUE( rando.isDivisibleBy(512,-262144) );
}

TEST(RandoTest, isNotDivisible)
{
	Rando rando;
	ASSERT_FALSE( rando.isDivisibleBy(3,2) );
	ASSERT_FALSE( rando.isDivisibleBy(2,3) );
	ASSERT_FALSE( rando.isDivisibleBy(262145,512) );
	ASSERT_FALSE( rando.isDivisibleBy(512,262145) );

	ASSERT_FALSE( rando.isDivisibleBy(-3,2) );
	ASSERT_FALSE( rando.isDivisibleBy(-2,3) );
	ASSERT_FALSE( rando.isDivisibleBy(-262145,512) );
	ASSERT_FALSE( rando.isDivisibleBy(-512,262145) );

	ASSERT_FALSE( rando.isDivisibleBy(3,-2) );
	ASSERT_FALSE( rando.isDivisibleBy(2,-3) );
	ASSERT_FALSE( rando.isDivisibleBy(262145,-512) );
	ASSERT_FALSE( rando.isDivisibleBy(512,-262145) );
}

TEST(RandoTest, isZeroDivisible)
{
	Rando rando;
	ASSERT_TRUE( rando.isDivisibleBy(1,0) );
	ASSERT_TRUE( rando.isDivisibleBy(0,1) );

	ASSERT_TRUE( rando.isDivisibleBy(-1,0) );
	ASSERT_TRUE( rando.isDivisibleBy(0,-1) );

	ASSERT_FALSE( rando.isDivisibleBy(0,0) );
 }

TEST(RandoTest, isPrime)
{
	Rando rando;
	ASSERT_TRUE( rando.isPrime(1) );
	ASSERT_TRUE( rando.isPrime(-1) );
  
	ASSERT_TRUE( rando.isPrime(2) );
	ASSERT_TRUE( rando.isPrime(-2) );

	ASSERT_TRUE( rando.isPrime(3) );
	ASSERT_TRUE( rando.isPrime(-3) );

	ASSERT_TRUE( rando.isPrime(5) );
	ASSERT_TRUE( rando.isPrime(-5) );
  
  if (sizeof(int) == 4)
  {
	  ASSERT_TRUE( rando.isPrime((int)0x7FFFFFFF) );
	  ASSERT_TRUE( rando.isPrime(-(int)0x7FFFFFFF) );
  }
}

TEST(RandoTest, isNotPrime)
{
	Rando rando;
	ASSERT_FALSE( rando.isPrime(4) );
	ASSERT_FALSE( rando.isPrime(-4) );
  
	ASSERT_FALSE( rando.isPrime(9) );
	ASSERT_FALSE( rando.isPrime(-9) );

  if (sizeof(int) == 4)
  {
	  ASSERT_FALSE( rando.isPrime((int)0x7FFFFFFE) );
	  ASSERT_FALSE( rando.isPrime((int)0x10000000) );
  }
}

TEST(RandoTest, isZeroPrime)
{
	Rando rando;
	ASSERT_FALSE( rando.isPrime(0) );
}
