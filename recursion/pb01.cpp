/*
 * Problem 1
Print "hi" n number of times using recursion
*/
#include <iostream>

using std::cin;
using std::cout;

void fn(int i, int n) {
  if (i > n)
    return;
  cout << i << " = " << "Hi" << '\n';
  fn(i + 1, n);
}
int main() {

  int n;
  cout << "Please enter the value of n : ";
  cin >> n;
  fn(1, n);

  return 0;
}
