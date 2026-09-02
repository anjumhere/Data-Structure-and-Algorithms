#include <iostream>

using std::cout;
/*
         pattern 1

                          *
                        * * *
                      * * * * *
                    * * * * * * *
                  * * * * * * * * *

            */

/*
            Pattern 2
                     * * * * * * * * *
                       * * * * * * *
                         * * * * *
                           * * *
                             *

*/

void pat1(int n) {
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

  /*
      we know that for outer loop we need 5 iterations 0-4
      */

  // for (int i = 0; i < n; i++) {
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
2
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

  for (int i = 0; i < n; i++) {
    // space at the beginning
    for (int j = 0; j < n - i - 1; j++) {
      cout << " ";
    }

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
  cout << "\n\n";
}
void pat2(int n) {
  /*       1         * * * * * * * * *   {0, 9, 0}
           2           * * * * * * *     {1, 7, 1}
           3              * * * * *      {2, 5, 2}
           4                * * *        {3, 3, 3}
           5                  *          {4, 1, 4}

  Its same as before , we just need to print everything in reverse order

Same patterns :
1. loop will run from 1 to 5
2. space + stars + space
3. printing stars as odd numbers


=====================================> For
spaces<===================================== its pretty simple , {0, 9, 0} => 0
spaces {1, 7, 1} => 1 spaces {2, 5, 2} => 2 spaces {3, 3, 3} => 3 spaces {4, 1,
4} => 4 spaces

  we will just follow the outer loop's i , it automatically goes from 1 to 5

===> Formula = > j<i;

--> Explanation

1st Iteration
   i = 0 j = 0
         output = no spaces
2nd iteration
   i = 1 j = 1
         output = 1 space
3rd iteration
   i = 2 j = 2
         output = 2 space
4th iteration
   i = 3 j = 3
         output = 3 space
3rd iteration
   i = 4 j = 4
         output = 4 space

         // We got exact results
  {0, 9, 0} => 0 spaces
  {1, 7, 1} => 1 spaces
  {2, 5, 2} => 2 spaces
  {3, 3, 3} => 3 spaces
  {4, 1, 4} => 4 spaces

=============================================> Stars
<===================================================== It usually depends on
your own formula and the method of doing it , there are multiple ways to do it.
How i figure out is that we need to print 9 stars in the begaining and do -2 in
every iteraion so it would become like

1. 9
2. 9-2 = 7
3. 7-2 = 5
4. 5-2 = 3
5. 3-1 = 1

1 - 3- 5- 7 - 9

so we need a formula which would subract 2 in every iteraion


         Formula ===> (2 * n)-(2 * i)-1
====> Explanation

  1st Iteration
 n = 5 , i = 0
 using formula  = (2 *5)-(2 * 0) -1 = 10 -0-1 = 9;
------> Result of first iteration ==> 9

 2st Iteration
 n = 5 , i = 1
 using formula  = (2 *5)-(2 * 1) -1 = 10 -2-1 = 7;
------> Result of second iteration ==> 7

3st Iteration
 n = 5 , i = 2
 using formula  = (2 *5)-(2 * 2) -1 = 10 -4-1 = 5;
------> Result of third iteration ==> 5

4st Iteration
 n = 5 , i = 3
 using formula  = (2 *5)-(2 * 3) -1 = 10 -6-1 = 3;
------> Result of fourth iteration ==> 3

5st Iteration
 n = 5 , i = 4
 using formula  = (2 *5)-(2 * 4) -1 = 10 -8-1 = 1;
------> Result of fifth iteration ==> 1



===> So the condition is fulfilled = 1, 3, 5, 7, 9

Summary
  formula for spaces = j<n
  formula for stars = (2*n)-(2*i)-1


  for code we would just use the spaces loop two times for getting back and
forth spaces,
*/

  // code

  for (int i = 0; i < n; i++) {
    // spaces
    for (int j = 0; j < i; j++) {
      cout << " ";
    }

    // stars
    for (int k = 0; k < (2 * n) - (2 * i) - 1; k++) {
      cout << "*";
    }
    for (int j = 0; j < i; j++) {
      cout << " ";
    }

    // Always add new line after each iteration
    cout << '\n';
  }
}
int main() {
  int n = 5;
  // pat1(n);
  pat2(n);
  return 0;
}
