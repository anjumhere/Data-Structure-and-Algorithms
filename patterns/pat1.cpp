#include <iostream>

/*
         pattern 1

   0           *               {4, 1, 4}
   1         * * *             {3, 3, 3}
   2       * * * * *           {2, 5, 2}
   3     * * * * * * *         {1, 7, 1}
   4   * * * * * * * * *       {0, 10,0}


*/

/*

        Solution
    we have 5 rows , now we know the outer loop;

   0           *               {4, 1, 4}
   1         * * *             {3, 3, 3}
   2       * * * * *           {2, 5, 2}
   3     * * * * * * *         {1, 7, 1}
   4   * * * * * * * * *       {0, 10,0}

if we see the pattern , there is nothing but.

space + stars + space


*/
int main() {

  for (int i = 0; i < 5; i++) {
  }
  return 0;
}
