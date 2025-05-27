// https://leetcode.com/problems/divide-two-integers/description/

#include <bits/stdc++.h>
using namespace std;

int divide(int dividend, int divisor) {
  bool sign = true;
  if (dividend < 0 && divisor >= 0) {
    sign = false;
  }
  if (dividend >= 0 && divisor < 0) {
    sign = false;
  }


  long quotient = 0;

  long div = abs((long long)dividend);
  long dvs = abs((long long)divisor);
cout << div << dvs << endl;
  while (div >= dvs) {
    int cnt = 0;
    while (div >= (dvs <<  cnt + 1)) {
      cnt++;
    }

    div -= dvs << cnt;

    quotient += 1 << cnt;
  }

  if (quotient > INT_MAX && sign) {
    return INT_MAX;
  }
  if (quotient < INT_MIN && sign == false) {
    return INT_MIN;
  }

  return sign ? (int)quotient : (int)-quotient;
}

int main() {
  // cout << divide(22, 3) << endl;
  // cout << divide(10, 3) << endl;
  cout << divide(-2147483648, -1) << endl;
}
