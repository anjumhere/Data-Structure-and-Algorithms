/*
Find the n-th Fibonacci number for a given non-negative integer n.
The Fibonacci sequence is defined as:

F(0) = 0
F(1) = 1
F(n) = F(n - 1) + F(n - 2) for n ≥ 2
*/
#include <iostream>

using std::cin;
using std::cout;

int fb() {
  int n;
  cout << "Enter the value of n :";
  cin >> n;

  if (n == 0)
    return 0;
  if (n == 1)
    return 1;

  int a = 0, b = 1;
  for (int i = 2; i <= n; i++) {
    int temp = a + b;
    a = b;
    b = temp;
  }
  return b;
}
int main() {
  int val = fb();
  cout << " values is :" << val;
}
