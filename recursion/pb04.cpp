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

// 2. Sum of first N natural numbers
int sumOfN(int n) {
  /*
      Base case: sum of 0 numbers is 0.
      If n reaches 0, there is nothing left to add, so return 0.

      Recursive case: sum(n) = n + sum(n-1)
      Each call adds the current n to the sum of everything before it.

      Example: sumOfN(4)
      = 4 + sumOfN(3)
      = 4 + 3 + sumOfN(2)
      = 4 + 3 + 2 + sumOfN(1)
      = 4 + 3 + 2 + 1 + sumOfN(0)
      = 4 + 3 + 2 + 1 + 0
      = 10
  */
  if (n == 0) {
    return 0;
  }
  return n + sumOfN(n - 1);
}

// 3. Nth Fibonacci number
int fibonacci(int n) {
  /*
      Fibonacci series: 0, 1, 1, 2, 3, 5, 8, 13, ...
      Each term is the sum of the two terms before it.

      Base cases:
      - fibonacci(0) = 0
      - fibonacci(1) = 1
      These stop the recursion since there's nothing before them to add.

      Recursive case: fib(n) = fib(n-1) + fib(n-2)
      We branch into two recursive calls and add their results.

      Example: fibonacci(5)
      = fib(4) + fib(3)
      = (fib(3)+fib(2)) + (fib(2)+fib(1))
      ... eventually breaks down to base cases and sums up to 5
  */
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return 1;
  }
  return fibonacci(n - 1) + fibonacci(n - 2);
}

// 4. Power of a number (x^n)
int power(int x, int n) {
  /*
      Base case: any number raised to the power 0 is 1.
      So if n == 0, return 1.

      Recursive case: x^n = x * x^(n-1)
      We keep multiplying x by the result of a smaller power,
      reducing n by 1 each time until it hits 0.

      Example: power(2, 4)
      = 2 * power(2, 3)
      = 2 * 2 * power(2, 2)
      = 2 * 2 * 2 * power(2, 1)
      = 2 * 2 * 2 * 2 * power(2, 0)
      = 2 * 2 * 2 * 2 * 1
      = 16
  */
  if (n == 0) {
    return 1;
  }
  return x * power(x, n - 1);
}

// 5. Sum of digits of a number
int sumOfDigits(int n) {
  /*
      Base case: if n becomes 0, there are no digits left to add,
      so return 0.

      Recursive case: take the last digit (n % 10), add it to the
      sum of digits of the remaining number (n / 10).

      Example: sumOfDigits(1234)
      = 4 + sumOfDigits(123)
      = 4 + 3 + sumOfDigits(12)
      = 4 + 3 + 2 + sumOfDigits(1)
      = 4 + 3 + 2 + 1 + sumOfDigits(0)
      = 4 + 3 + 2 + 1 + 0
      = 10
  */
  if (n == 0) {
    return 0;
  }
  return (n % 10) + sumOfDigits(n / 10);
}

int main() {
  cout << factorial(5) << endl;
  // cout << sumOfN(10) << endl;
  // cout << fibonacci(7) << endl;
  // cout << power(2, 5) << endl;
  // cout << sumOfDigits(9876) << endl;

  return 0;
}
