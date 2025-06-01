// https://leetcode.com/problems/number-of-1-bits/?envType=problem-list-v2&envId=a0pb9aqc
// 191. Number of 1 Bits

#include <bits/stdc++.h>
using namespace std;

int hammingWeight(int n) {
  int count = 0;

  while (n > 0) {
    count += n & 1;
    n >>= 1;
  }

  return count;
}

int main() {
  cout <<hammingWeight(11) << endl;
}
