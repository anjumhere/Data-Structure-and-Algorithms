#include <iostream>

/*
         pattern 1

              *
            * * *
          * * * * *
        * * * * * * *
      * * * * * * * * *


*/

/*

        Solution
    we have 5 rows , now we know the outer loop;

   0           *               {4, 1, 4}
   1         * * *             {3, 3, 3}
   2       * * * * *           {2, 5, 2}
   3     * * * * * * *         {1, 7, 1}
   4   * * * * * * * * *       {0, 9, 0}

if we see the pattern , there is nothing but.

space + stars + space


*/

using std::cout;
int main() {
  /*
      we know that for outer loop we need 5 iterations 0-4
      */

  int n = 5;
  for (int i = 0; i < n; i++) {

    /*
   ------------> Spaces
{4, 1, 4} => numbers at the start and beginning are spaces , if we look at the
order {3, 3, 3}    its decreasing from 4 to 0; {2, 5, 2} -> so we need a formula
which would decrease the  value by one in every iteration {1, 7, 1}  == Formula
=>> n-i-1 {0, 9, 0}


--------------> Explanation of formula
1st iteration
n = 5 , i = 0 ===> 5-0-1 = 4; we got 4 spaces now
2nd iteration
n = 5 , i = 1 ===> 5-1-1 = 3; we got 3 spaces now
3rd iteration
n = 5 , i = 2 ===> 5-2-1 = 2; we got 2 spaces now
4th iteration
n = 5 , i = 3 ===> 5-3-1 = 1; we got 1 space now
5th iteration
n = 5 , i = 4 ===> 5-4-1 = 0; no space at the end
      */

    // space at the beginning
    for (int j = 0; j < n - i - 1; j++) {
      cout << " ";
    }

    /*
      -----------------> Stars
{4, 1, 4} => values at the center are the  stars.
{3, 3, 3} --> if we look closely its a sequence of odd numbers 1,3,5,7,9
{2, 5, 2} --> We need to print one start at the first iteration then 3 then 5
then 7 then 9 {1, 7, 1} --> so we need a formula to increse the value of i by
i+2; {0, 9, 9}

 ----------Formula ==> 2*i+1
==============> Explanation of formula (2*i+1)
1st iteration
i = 0
2 x 0 +1 = 1
2nd iteration
i = 1
2 x 1 +1 = 3
3rd iteration
i = 2
2 x 2 +1 = 5
4nd iteration
i = 3
2 x 3 +1 = 7
5nd iteration
i = 4
2 x 4 +1 = 9

*/

    // Stars
    for (int k = 0; k < (2 * i + 1); k++) {
      cout << "*";
    }

    // space at the end
    for (int j = 0; j < n - i - 1; j++) {
      cout << " ";
    }

    // add a new line at each iteration of the  outer  loop
    cout << '\n';
  }
  return 0;
}
