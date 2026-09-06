#include <cmath>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::sqrt;
using std::vector;

vector<int> quadraticRoots(int a, int b, int c) {
  // value holders
  vector<int> roots;
  vector<int> imag;
  imag.push_back(-1);

  // finding discriminent
  double discrim = b * b - 4 * a * c;

  // returning imaginary
  if (discrim < 0)
    return imag;

  // applying quadratic formula to get real roots;

  double root1 = (-b - sqrt(discrim));
  root1 = root1 / (2 * a);

  double root2 = (-b + sqrt(discrim));
  root2 = root2 / (2 * a);

  // storing real roots in the array;

  roots.push_back(floor(root2));
  roots.push_back(floor(root1));
  return roots;
}
int main() {
  int a, b, c;
  cout << "Enter the values of a | b | c :";
  cin >> a >> b >> c;
  vector<int> vals = quadraticRoots(a, b, c);

  for (auto val : vals) {
    cout << val;
  }
  return 0;
}
