/*
 * Problem 1: Find the sum of first n Numbers;
 *
 */
#include <iostream>

using std::cin;
using std::cout;

void fn(int n, int sum) {
  if (n < 1) {
    cout << sum << '\n';
    return;
  }
  fn(n - 1, sum + n);
};
int main() {
  int n;
  cout << "Enter the Number: ";
  cin >> n;
  fn(n, 0);

  return 0;
}
