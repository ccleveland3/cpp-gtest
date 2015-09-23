/**
 * Rando Class Definition
 * Author: Christian Cleveland
**/

#include <math.h>
#include "rando.h"

/**
 * Worry if only one child is smiling or if all children are smiling
**/
bool Rando::shouldWorry(bool childASmile, bool childBSmile, bool childCSmile)
{
	return (childASmile ^ childBSmile ^ childCSmile);
}
/**
 * Determines if first or second are evenly divisible by the other.
**/
bool Rando::isDivisibleBy(int first, int second)
{
  if (first == 0 && second == 0)
    return false;
  else if (first == 0 || second == 0)
    return true;
  else if ((first % second == 0) || (second % first == 0))
    return true;
  else
	  return false;
}

/**
 * Given a number, num, says whether or not that number is prime
 * (that is, only evenly divisible by itself and 1. For the sake
 * of this function, do NOT consider 0 prime)
**/
bool Rando::isPrime(int num)
{
  int i;
  int squrtNum;

  /* Absolute value */
  num = (num < 0) ? -num : num;

  if (num == 0)
    return false;

  /* Handling evens here so that the for loop below can be reduced to dividing
   * by only odds since all evens are divisible by 2.
   */
  else if (num == 2)
    return true;
  else if (num % 2 == 0)
    return false;

  /* If num is a prime, it will be evenly divided by a number between 2 and
   * squrt(num) and we only need to find one instance.  "i" is incremented by 2
   * because all evens were taken care of above.
   */
  squrtNum = sqrt(num);
  for (i = 3; (i <= squrtNum); i = i + 2)
    if(num % i == 0)
      return false;

	return true;
}

/**
 * Given two numbers, first and second, return the value of the one
 * that is closest to zero without actually being zero.
**/
int Rando::nearestToZero(int a, int b)
{
  if (a == 0 || b == 0)
    return (a != 0) ? a : b;

  int absA = (a < 0) ? -a : a;
  int absB = (b < 0) ? -b : b;

  return (absA < absB) ? a : b;
}
