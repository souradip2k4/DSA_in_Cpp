// https://leetcode.com/problems/powx-n/
// 50. Pow(x, n)

#include <bits/stdc++.h>
using namespace std;

double myPow(double x, int n) {
  if (n == 0) return 1;
  long nn = n; // If power is -ve int range overflow can occur so we use long
  if (nn < 0) {
    nn = -1 * nn;
  }

  double temp = myPow(x, nn / 2);
  double res;
  if (nn % 2 == 0) {
    res = temp * temp;
  } else {
    res = x * temp * temp;
  }

  if (n < 0) {
    return (double)1/(double)res;
  } else {
    return res;
  }
}

int main() {
  cout << myPow(2.00000, 10) << endl;
  cout << myPow(2.10000, 3) << endl;
  cout << myPow(2.00000, -2) << endl;
}
