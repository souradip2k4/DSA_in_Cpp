// https://leetcode.com/problems/minimum-bit-flips-to-convert-number/

#include <bits/stdc++.h>
using namespace std;

int minBitFlips(int start, int goal) {
  int count = 0;
  while (start > 0) {
    // start >= 0 will cause infinite loop because 0 >> 1 = 0
    if (!(start & 1) == (goal & 1)) {
      count++;
    }

    start = start >> 1;
    goal = goal >> 1;
  }

  while (goal > 0) {
    // goal >= 0 will cause infinite loop because 0 >> 1 = 0 so not used

    // Start = 1010 Goal = 1010010
    // The 5th bit from right of both the binary nos is 0 so no flipping will occur This condition prevents it
    if ((goal & 1) != 0) {
      count++;
    }
    goal = goal >> 1;
  }

  return count;
}


int main() {
  cout << minBitFlips(10, 7) << endl;
  cout << minBitFlips(3, 4) << endl;
  cout << minBitFlips(10, 82) << endl;
}
