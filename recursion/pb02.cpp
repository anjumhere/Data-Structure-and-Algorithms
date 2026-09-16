/*
First n Fibonacci using Recursion
Given a number n, return an array containing the first n Fibonacci numbers.

The first two Fibonacci numbers are 0 and 1.
Each subsequent Fibonacci number is obtained by adding the previous two numbers.
Examples:

Input: n = 5
Output: [0, 1, 1, 2, 3]
Explanation: The first 5 Fibonacci numbers are 0, 1, 1, 2, 3.
  */

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

vector<int> fn(int n, vector<int> &res) { return n; }
int main() {
  vector<int> res;
  int n;
  cout << "Enter the value of n :";
  cin >> n;
  res = fn(n, res);

  return 0;
}
