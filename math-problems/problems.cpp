/*
    ============================================================
    Problems in this file
    ============================================================
    1a. Reverse the integer n using a vector
    1b. Find the total number of digits in n using a vector
    3.  Reverse a number without using any array/vector/container
    4.  Check if a number is a palindrome
    5.  Check if a number is an Armstrong number
    6.  List all the divisors of n
    ============================================================
*/

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

void pb1(int n) {
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
  vector<int> vec;

  while (n > 0) {
    int last_digit = n % 10;
    vec.push_back(last_digit);
    n /= 10;
  }

  // vec now holds the digits in reverse order of the original number
  for (int val : vec) {
    cout << val;
  }
  cout << '\n';
}

void pb2(int n) {
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
  vector<int> vec;

  // You can also solve this problem using log10.
  int count = static_cast<int>(log10(n) + 1);
  cout << "count ==> " << count << '\n';

  while (n > 0) {
    int last_digit = n % 10;
    vec.push_back(last_digit);
    n /= 10;
  }

  // vec now has exactly as many elements as n had digits
  cout << "Size of the vector is : " << vec.size() << '\n';
}

void pb3() {
  /*
      Problem 3: Reverse a number without using any array, vector,
      or other container.
      Approach:
      - Use basic maths instead of storage.
      - Repeatedly extract the last digit of n using (n % 10)
      - Build up the reversed number by shifting it left one
        decimal place (num * 10) and adding the extracted digit
      - Remove the last digit from n using (n / 10)
      Example:
      n = 7789 -> num builds up as 9 -> 98 -> 987 -> 9878
  */
  int n;
  cin >> n;

  int num = 0;
  while (n > 0) {
    int last = n % 10;
    n /= 10;
    num = (num * 10) + last;
  }

  cout << "The reversed number is : " << num << '\n';
}

void pb4() {
  /*
      Problem 4: Check if a number is a palindrome.
      Approach:
      - Save the original number before modifying it.
      - Reverse the number using the same digit-by-digit technique
        as pb3 (extract with % 10, rebuild with * 10 + last).
      - Compare the reversed number to the original.
      - If they match, the number reads the same forwards and
        backwards, so it is a palindrome.
      Example:
      n = 121 -> reversed = 121 -> palindrome
      n = 123 -> reversed = 321 -> not a palindrome
  */
  int n;
  cin >> n;

  int orig = n;
  int num = 0;
  while (n > 0) {
    int last = n % 10;
    n /= 10;
    num = (num * 10) + last;
  }

  cout << "The original number = " << orig << '\n';
  cout << "The reversed number is : " << num << '\n';

  if (num == orig) {
    cout << "Yes, this is a palindrome number\n";
  } else {
    cout << "This is not a palindrome number\n";
  }
}

void pb5() {
  /*
      Problem 5: Check if a number is an Armstrong number.
      Approach:
      - A k-digit number is an Armstrong number if the sum of each
        digit raised to the power k equals the number itself.
      - First find k, the digit count, using log10(n) + 1.
      - Loop through each digit (extract with % 10, remove with / 10),
        raise it to the power k using a manual multiplication loop
        (avoids pow()'s floating-point imprecision), and accumulate
        the sum.
      - Compare the sum to the original number.
      - Use int64_t throughout the accumulation to avoid integer
        overflow, since the sum can exceed int range for larger inputs.
      Example:
      n = 153 -> k = 3 -> 1^3 + 5^3 + 3^3 = 153 -> Armstrong number
  */
  int n;
  cout << "Enter the number : ";
  cin >> n;

  int orig = n;
  int count = static_cast<int>(log10(n) + 1);
  cout << "Total digits are : " << count << "\n\n";

  int64_t sum = 0;
  while (n > 0) {
    int64_t last = n % 10;

    int64_t term = 1;
    for (int i = 0; i < count; i++) {
      term *= last;
    }

    sum += term;
    n /= 10;
  }

  if (sum == orig) {
    cout << "It's an Armstrong Number\n";
  } else {
    cout << "Not an Armstrong Number\n";
  }
}

void pb6() {
  /*
      Problem 6: Print all divisors of a number, marked as divisible
      or not.
      Approach:
      - Loop i from 1 up to and including n, since every number
        is divisible by itself.
      - For each i, check if n % i == 0.
      - If the remainder is 0, i divides n evenly, so mark it
        with a checkmark (✓).
      - Otherwise, mark it with an x.
      Example:
      n = 10 -> 1 ✓, 2 ✓, 3 x, 4 x, 5 ✓, 6 x, 7 x, 8 x, 9 x, 10 ✓
  */
  vector<int> div;
  vector<int> ndiv;
  int n;
  cout << "Enter the number to find all its divisors :";
  cin >> n;

  for (int i = 1; i <= n; i++) {
    if (n % i == 0) {
      div.push_back(i);
    } else {
      ndiv.push_back(i);
    }
  }
  cout << "Divisors = ";
  for (int val : div) {
    cout << val << " ";
  }

  cout << "\n\n";
  cout << "non-divisors = ";

  for (int val : ndiv) {
    cout << val << " ";
  }
}

bool pb7() {

  // Chec if n is a prime number

  int n;
  cout << "Please enter the number : ";
  cin >> n;
  if (n <= 1)
    return false;
  if (n <= 3)
    return true;
  int limit = static_cast<int>(sqrt(n));
  for (int i = 2; i <= limit; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

void pb8() {
  int n1 = 3;
  int n2 = 14;
  int hcf = 0;
  for (int i = std::min(n1, n2); i >= 1; i--) {
    if (n1 % i == 0 && n2 % i == 0) {
      hcf = i;
      break;
    }
  }
  cout << "hcf == " << hcf << '\n';
}
int main() {
  // int n = 7789;
  // pb1(n);
  // jb2(n);
  // pb3();
  // pb4();
  // pb5();
  // pb6();
  /*
  if (pb7()) {
    cout << "Its Prime number\n";
  } else {
    cout << "Its not a prime number\n";
  }
*/
  pb8();

  return 0;
}
