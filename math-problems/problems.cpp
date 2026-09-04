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
#include <iostream>
#include <vector>

using std::cout;
using std::vector;

void pb1(int n) {
  vector<int> vec;

  while (n > 0) {
    int last_digit = n % 10;   // extract last digit of n
    vec.push_back(last_digit); // store it in the vector
    n = n / 10;                // remove last digit from n
  }

  /*
      vec now holds the digits in reverse order
      of the original number
  */
  for (int val : vec) {
    cout << val; // prints 9878, which is 7789 reversed
  }
  cout << '\n';
}
void pb2(int n) {
  vector<int> vec;

  while (n > 0) {
    int last_digit = n % 10;   // extract last digit of n
    vec.push_back(last_digit); // store it (one push per digit)
    n = n / 10;                // remove last digit from n
  }

  /*
      vec now has exactly as many elements
      as n had digits
  */
  cout << "Size of the vector is : " << vec.size() << '\n'; // prints 4
}
int main() {
  int n = 7789;
  pb1(n);
  pb2(n);
  return 0;
}
