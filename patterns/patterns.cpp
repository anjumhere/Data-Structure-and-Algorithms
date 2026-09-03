#include <iostream>

using std::cout;

/*
    Pattern 1

                      *
                    * * *
                  * * * * *
                * * * * * * *
              * * * * * * * * *
*/

#include <iostream>

using std::cout;

/*
    Pattern 1

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

/*
    Pattern 3

                      *
                    * * *
                  * * * * *
                * * * * * * *
              * * * * * * * * *
              * * * * * * * * *
                * * * * * * *
                  * * * * *
                    * * *
                      *
*/

void pat1(int n) {
  /*
      SOLUTION
      --------
      We have 5 rows, now we know the outer loop.

       i          Row                    {space, stars, space}
      ---   ------------------------     ----------------------
       0             *                        {4, 1, 4}
       1           * * *                      {3, 3, 3}
       2         * * * * *                    {2, 5, 2}
       3       * * * * * * *                  {1, 7, 1}
       4     * * * * * * * * *                {0, 9, 0}

      If we look at the pattern, there is nothing but:

          space + stars + space

      We know that for the outer loop we need 5 iterations (0 to 4).
  */

  // for (int i = 0; i < n; i++) {

  /*
      SPACES
      ------
      {4, 1, 4} => the numbers at the start and end are spaces.
      {3, 3, 3} -> if we look at the order, it's decreasing from 4 to 0.
      {2, 5, 2} -> so we need a formula which decreases the value by
      {1, 7, 1}    one in every iteration.
      {0, 9, 0}

      Formula => n - i - 1

      Explanation of formula:

          1st iteration : n = 5, i = 0  =>  5 - 0 - 1 = 4   (4 spaces)
          2nd iteration : n = 5, i = 1  =>  5 - 1 - 1 = 3   (3 spaces)
          3rd iteration : n = 5, i = 2  =>  5 - 2 - 1 = 2   (2 spaces)
          4th iteration : n = 5, i = 3  =>  5 - 3 - 1 = 1   (1 space)
          5th iteration : n = 5, i = 4  =>  5 - 4 - 1 = 0   (no space)


      STARS
      -----
      {4, 1, 4} => the values at the center are the stars.
      {3, 3, 3} -> if we look closely it's a sequence of odd numbers: 1,3,5,7,9
      {2, 5, 2} -> we need to print one star at the first iteration, then 3,
      {1, 7, 1}    then 5, then 7, then 9.
      {0, 9, 9} -> so we need a formula to increase the value by i+2.

      Formula => 2*i + 1

      Explanation of formula (2*i + 1):

          1st iteration : i = 0  =>  2*0 + 1 = 1
          2nd iteration : i = 1  =>  2*1 + 1 = 3
          3rd iteration : i = 2  =>  2*2 + 1 = 5
          4th iteration : i = 3  =>  2*3 + 1 = 7
          5th iteration : i = 4  =>  2*4 + 1 = 9
  */

  for (int i = 0; i < n; i++) {
    // space at the beginning
    for (int j = 0; j < n - i - 1; j++) {
      cout << " ";
    }

    // stars
    for (int k = 0; k < (2 * i + 1); k++) {
      cout << "*";
    }

    // space at the end
    for (int j = 0; j < n - i - 1; j++) {
      cout << " ";
    }

    // add a new line at each iteration of the outer loop
    cout << '\n';
  }

  cout << "\n\n";
}

void pat2(int n) {
  /*
       i          Row                    {space, stars, space}
      ---   ------------------------     ----------------------
       0     * * * * * * * * *                {0, 9, 0}
       1       * * * * * * *                  {1, 7, 1}
       2         * * * * *                    {2, 5, 2}
       3           * * *                      {3, 3, 3}
       4             *                        {4, 1, 4}

      It's the same as before, we just need to print everything in
      reverse order.

      Same patterns:
          1. Loop will run from 0 to 4 (5 rows).
          2. space + stars + space
          3. Stars printed as odd numbers.


      SPACES
      ------
      Pretty simple:

          {0, 9, 0} => 0 spaces
          {1, 7, 1} => 1 space
          {2, 5, 2} => 2 spaces
          {3, 3, 3} => 3 spaces
          {4, 1, 4} => 4 spaces

      We just follow the outer loop's i, it automatically goes from 0 to 4.

      Formula => j < i

      Explanation:

          1st iteration : i = 0, j = 0  =>  no spaces
          2nd iteration : i = 1, j = 1  =>  1 space
          3rd iteration : i = 2, j = 2  =>  2 spaces
          4th iteration : i = 3, j = 3  =>  3 spaces
          5th iteration : i = 4, j = 4  =>  4 spaces

      // We got the exact results:
          {0, 9, 0} => 0 spaces
          {1, 7, 1} => 1 space
          {2, 5, 2} => 2 spaces
          {3, 3, 3} => 3 spaces
          {4, 1, 4} => 4 spaces


      STARS
      -----
      This usually depends on your own formula and method of doing it —
      there are multiple ways to do it.

      How I figured it out: we need to print 9 stars at the beginning
      and subtract 2 in every iteration, so it becomes:

          1. 9
          2. 9 - 2 = 7
          3. 7 - 2 = 5
          4. 5 - 2 = 3
          5. 3 - 2 = 1

          1 - 3 - 5 - 7 - 9

      So we need a formula which subtracts 2 in every iteration.

      Formula => (2 * n) - (2 * i) - 1

      Alternative formulas you can use:
          (2 * n - 1) - (2 * i)
          (2 * n) - (2 * i - 1)

      Explanation:

          1st iteration : n = 5, i = 0
              (2*5) - (2*0) - 1 = 10 - 0 - 1 = 9

          2nd iteration : n = 5, i = 1
              (2*5) - (2*1) - 1 = 10 - 2 - 1 = 7

          3rd iteration : n = 5, i = 2
              (2*5) - (2*2) - 1 = 10 - 4 - 1 = 5

          4th iteration : n = 5, i = 3
              (2*5) - (2*3) - 1 = 10 - 6 - 1 = 3

          5th iteration : n = 5, i = 4
              (2*5) - (2*4) - 1 = 10 - 8 - 1 = 1

      So the condition is fulfilled: 1, 3, 5, 7, 9


      SUMMARY
      -------
          formula for spaces = j < n
          formula for stars  = (2 * n) - (2 * i) - 1

      For code, we would just use the spaces loop two times to get
      the leading and trailing spaces.
  */

  // code

  cout << "=> Printing inverse pyramid <=\n\n";

  for (int i = 0; i < n; i++) {
    // spaces
    for (int j = 0; j < i; j++) {
      cout << " ";
    }

    // stars
    for (int k = 0; k < (2 * n - 1) - (2 * i); k++) {
      cout << "*";
    }

    // trailing spaces
    for (int j = 0; j < i; j++) {
      cout << " ";
    }

    // always add new line after each iteration
    cout << '\n';
  }
}

void pat3(int n) {
  /*
      SOLUTION
      --------

          Pattern:
                            *
                          * * *
                        * * * * *
                      * * * * * * *
                    * * * * * * * * *
                    * * * * * * * * *
                      * * * * * * *
                        * * * * *
                          * * *
                            *

      If you notice, this is the pyramid (Pattern 1) stacked directly
      on top of the inverted pyramid (Pattern 2):

                            *
                          * * *
                        * * * * *
                      * * * * * * *
                    * * * * * * * * *
                              +
                    * * * * * * * * *
                      * * * * * * *
                        * * * * *
                          * * *
                            *

      We already know how to build both pyramids, so we just combine
      the two loops we already derived:

          1. Normal pyramid (Pattern 1):
                 formula for spaces = n - i - 1
                 formula for stars  = 2*i + 1

          2. Inverted pyramid (Pattern 2):
                 formula for spaces = j < i
                 formula for stars  = (2*n - 1) - (2*i)

      Now we just run both loops back to back.
  */

  // normal pyramid
  for (int i = 0; i < n; i++) {
    // spaces
    for (int j = 0; j < n - i - 1; j++) {
      cout << " ";
    }

    // stars
    for (int k = 0; k < (2 * i + 1); k++) {
      cout << "*";
    }

    // trailing spaces
    for (int j = 0; j < n - i - 1; j++) {
      cout << " ";
    }

    cout << '\n';
  }

  // inverted pyramid
  for (int i = 0; i < n; i++) {
    // spaces
    for (int j = 0; j < i; j++) {
      cout << " ";
    }

    // stars
    for (int k = 0; k < (2 * n - 1) - (2 * i); k++) {
      cout << "*";
    }

    // trailing spaces
    for (int j = 0; j < i; j++) {
      cout << " ";
    }

    cout << '\n';
  }
}

int main() {
  int n = 5;
  // pat1(n);
  // pat2(n);
  pat3(n);
  return 0;
}
