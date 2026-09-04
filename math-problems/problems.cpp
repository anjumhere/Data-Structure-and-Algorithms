// Problem 1a: Reverse the integer n using a vector
// Approach: repeatedly extract the last digit of n using n % 10,
// push it into a vector, then remove that digit from n using n / 10.
// Since we extract digits starting from the last one, printing the
// vector in the order we filled it gives us the reversed number.

#include <iostream>
#include <vector>
using std::cout;
using std::vector;

int main() {
  vector<int> vec;
  int n = 7789;

  while (n > 0) {
    int last_digit = n % 10;   // get the last digit of n
    vec.push_back(last_digit); // store it in the vector
    n = n / 10;                // remove the last digit from n
  }

  // vec now holds the digits in reverse order of the original number
  // e.g. for n = 7789 -> vec = {9, 8, 7, 7}
  for (int val : vec) {
    cout << val; // prints 9878, which is 7789 reversed
    //
  }
  cout << '\n';

  return 0;
}
