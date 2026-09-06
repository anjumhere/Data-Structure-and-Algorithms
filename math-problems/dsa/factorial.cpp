#include <iostream>

using std::cin;
using std::cout;

void fct() {
  int n;
  cout << "Please enter the number :";
  cin >> n;
  int fct = 1;
  for (int i = 1; i <= n; i++) {
    fct *= i;
  }
  cout << "Factorial = " << fct << '\n';
}
int main() {
  fct();
  return 0;
}
