// https://leetcode.com/problems/powx-n/
// 50. Pow(x, n)

#include <bits/stdc++.h>
using namespace std;

// Approach 1
double myPow(double x, int n) {
  if (n == 0) return 1;
  long nn = n; // If power is -ve int range overflow can occur so we use long
  if (nn < 0) {
    nn = -1 * nn; // -1 * n will cause range overflow error
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

// Approach 2
/*double myPow(double x, int n) {
  double res = 1.0;

  long nn = n;
  if (nn < 0) {
    nn = -1 * nn;
  }

  for (long i = 0; i < nn ; i ++) {
    res = res * x;
  }

  if (n < 0) {
    return (double)1.0/ (double)res;
  }

  return res;
}*/

int main() {
  cout << myPow(2.00000, 10) << endl;
  cout << myPow(2.10000, 3) << endl;
  cout << myPow(2.00000, -2) << endl;
}
