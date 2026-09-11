/*
 * Problem 1: Print "Hi" n number of times using recursion
 */

#include <iostream>

using std::cin;
using std::cout;

/**
 * Recursively prints "Hi" from i up to n.
 *
 * @param i  current counter (starts at 1)
 * @param n  target number of times to print
 */
void printHi(int i, int n) {
  // Base case: stop recursion once i exceeds n
  if (i > n) {
    return;
  }

  cout << i << " = Hi\n";

  // Recursive case: move to the next number
  printHi(i + 1, n);

  /*
   * Understanding printHi(i + 1, n):
   *
   * This is the heart of the recursion. Each call to printHi() doesn't
   * loop internally — instead, it calls a fresh copy of ITSELF with an
   * updated value of i, and that copy handles the "next step" of the
   * counting. The variable n never changes; it's just passed along
   * unchanged so every call knows where to stop.
   *
   * "i + 1" is what actually drives the recursion forward. Instead of
   * incrementing i with something like i++ (which mutates the current
   * i), we compute the NEXT value (i + 1) and hand it off as the
   * starting i of the next call. The current function's own i stays
   * untouched — each call has its own separate copy of i on the call
   * stack, so nothing gets overwritten.
   *
   * Full trace for n = 3, starting with printHi(1, 3):
   *
   *   printHi(1, 3)
   *     -> 1 > 3? No.
   *     -> prints "1 = Hi"
   *     -> calls printHi(1 + 1, 3) = printHi(2, 3)
   *
   *       printHi(2, 3)
   *         -> 2 > 3? No.
   *         -> prints "2 = Hi"
   *         -> calls printHi(2 + 1, 3) = printHi(3, 3)
   *
   *           printHi(3, 3)
   *             -> 3 > 3? No.
   *             -> prints "3 = Hi"
   *             -> calls printHi(3 + 1, 3) = printHi(4, 3)
   *
   *               printHi(4, 3)
   *                 -> 4 > 3? Yes -> base case hit -> return
   *                 (nothing is printed, recursion unwinds from here)
   *
   * So each call is responsible for exactly one print, then delegates
   * "the rest of the counting" to the next call by passing i + 1.
   * The recursion keeps going deeper until the base case (i > n)
   * finally stops it — at which point all the calls simply return,
   * one by one, back up to main().
   */
}

int main() {
  int n;

  cout << "Please enter the value of n: ";
  cin >> n;

  // First argument (1) is the starting counter,
  // second argument (n) is the target count.
  printHi(1, n);

  return 0;
}
