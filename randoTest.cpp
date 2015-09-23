/**
 * Unit Tests for Rando Test
 * Author: Christian Cleveland
**/

#include <gtest/gtest.h>
#include "rando.h"
 
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

TEST(RandoTest, isNearestToZero)
{
	Rando rando;
	ASSERT_EQ( rando.nearestToZero(1,2), 1 );
	ASSERT_EQ( rando.nearestToZero(1,-2), 1 );
	ASSERT_EQ( rando.nearestToZero(-1,2), -1 );
	ASSERT_EQ( rando.nearestToZero(-1,-2), -1 );

	ASSERT_EQ( rando.nearestToZero(2,1), 1 );
	ASSERT_EQ( rando.nearestToZero(2,-1), -1 );
	ASSERT_EQ( rando.nearestToZero(-2,1), 1 );
	ASSERT_EQ( rando.nearestToZero(-2,-1), -1 );

	ASSERT_EQ( rando.nearestToZero(1,1), 1 );
	ASSERT_EQ( rando.nearestToZero(-1,-1), -1 );

  int retval = rando.nearestToZero(-1,1);
  ASSERT_TRUE( (retval == 1 || retval == -1) );

	ASSERT_EQ( rando.nearestToZero(100,200), 100 );
	ASSERT_EQ( rando.nearestToZero(100,-200), 100 );
	ASSERT_EQ( rando.nearestToZero(-100,200), -100 );
	ASSERT_EQ( rando.nearestToZero(-100,-200), -100 );

  if (sizeof(int) == 4)
  {
    retval = rando.nearestToZero((int)0x7FFFFFFF, (int)0x10000000);
    ASSERT_EQ(retval, (int)0x10000000);
    
    retval = rando.nearestToZero((int)0x7FFFFFFF, (int)0x7FFFFFFF);
    ASSERT_EQ(retval, (int)0x7FFFFFFF);

    retval = rando.nearestToZero((int)0x10000000, (int)0x10000000);
    ASSERT_EQ(retval, (int)0x10000000);
  }
}

TEST(RandoTest, isZeroNearestToZero)
{
	Rando rando;
	ASSERT_EQ( rando.nearestToZero(0,1), 1);
	ASSERT_EQ( rando.nearestToZero(1,0), 1);

	ASSERT_EQ( rando.nearestToZero(0,-1), -1);
	ASSERT_EQ( rando.nearestToZero(-1,0), -1);
  
	ASSERT_EQ( rando.nearestToZero(0,0), 0);
}
