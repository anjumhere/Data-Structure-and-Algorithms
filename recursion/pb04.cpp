#include <iostream>
using namespace std;

/*
    QUESTIONS:

    1. Factorial of a number
       Find the factorial of a given number n using recursion.

    2. Sum of first N natural numbers
       Find the sum 1 + 2 + 3 + ... + n using recursion.

    3. Nth Fibonacci number
       Find the nth term of the Fibonacci series using recursion.

    4. Power of a number (x^n)
       Calculate x raised to the power n using recursion.

    5. Sum of digits of a number
       Find the sum of all digits of a given number using recursion.
*/

// 1. Factorial of a number
int factorial(int n) {
  /*
      Base case: factorial(0) = 1, factorial(1) = 1
      so if n is 0 or 1, we stop recursing and return 1.

      Recursive case: n! = n * (n-1)!
      So we call factorial(n-1) and multiply the result by n.

      Example: factorial(4)
      = 4 * factorial(3)
      = 4 * 3 * factorial(2)
      = 4 * 3 * 2 * factorial(1)
      = 4 * 3 * 2 * 1
      = 24
  */
  if (n == 0 || n == 1) {
    return 1;
  }
  return n * factorial(n - 1);
}

int main() {
  cout << factorial(5) << endl;
  // cout << sumOfN(10) << endl;
  // cout << fibonacci(7) << endl;
  // cout << power(2, 5) << endl;
  // cout << sumOfDigits(9876) << endl;

  return 0;
}
