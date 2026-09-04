/*
    Problem 1a: Reverse the integer n using a vector

    Approach:
    - Repeatedly extract the last digit of n using (n % 10)
    - Push that digit into a vector
    - Remove the last digit from n using (n / 10)
    - Since we extract digits starting from the last one,
      printing the vector in the order we filled it gives
      us the reversed number

    Example:
    n = 7789 -> vec = {9, 8, 7, 7} -> printed as 9878
*/

/*
    Problem 1b: Find the total number of digits in n using a vector

    Approach:
    - Same digit-extraction loop as reversing the number
    - Repeatedly extract the last digit of n using (n % 10)
    - Push that digit into a vector
    - Remove the last digit from n using (n / 10)
    - We don't care about the order of digits here, only how
      many got pushed, so vec.size() gives us the digit count

    Example:
    n = 7789 -> vec = {9, 8, 7, 7} -> size = 4
*/

#include <cmath>
#include <iostream>
#include <vector>

using std::cout;
using std::vector;

void pb1(int n) {
  vector<int> vec;

  while (n > 0) {
    // extract last digit of n
    int last_digit = n % 10;
    // store it in the vector
    vec.push_back(last_digit);
    // remove last digit from n
    n = n / 10;
  }

  // vec now holds the digits in reverse order of the original number
  for (int val : vec) {
    cout << val;
  }
  cout << '\n';
}

void pb2(int n) {
  vector<int> vec;
  // you can also solve this problem by using log10
  int count = static_cast<int>((log10(n) + 1));
  cout << "count ==> " << count << '\n';

  while (n > 0) {
    // extract last digit of n
    int last_digit = n % 10;
    // store it (one push per digit)
    vec.push_back(last_digit);
    // remove last digit from n
    n = n / 10;
  }

  // vec now has exactly as many elements as n had digits
  cout << "Size of the vector is : " << vec.size() << '\n';
}

void pb3(int n) {
  /*
  Reverse the number without using any array or vector and any kind of
  container.
    */

  // We will use basic maths to solve this problem.

  int num = 0;
  while (n > 0) {
    int last = n % 10;
    n /= 10;

    num = (num * 10) + last;
  }
  cout << "The reversed number is : " << num << '\n';
}
int main() {
  int n = 7789;
  pb1(n);
  pb2(n);
  pb3(n);
  return 0;
}
