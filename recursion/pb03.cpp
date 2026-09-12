/*
-> Problems
1. print from n to 1
2. print from 1 to n but by backtracking
3. print from n to 1 but by backtracking
*/
#include <iostream>

using std::cin;
using std::cout;

void fa(int i, int n) {
  if (i < 1)
    return;
  cout << "val = " << i << '\n';
  fa(i - 1, n);
}

void fb(int i, int n) {

  if (i < 1)
    return;
  fb(i - 1, n);
  cout << "Val = " << i << '\n';
}
void fc(int i, int n) {

  if (i > n)
    return;
  fc(i + 1, n);
  cout << "Val = " << i << '\n';
}
int main() {

  int n;

  cout << "Enter the value of n :";
  cin >> n;
  // fa(n, n);
  // fb(n, n);
  fc(1, n);

  return 0;
}
