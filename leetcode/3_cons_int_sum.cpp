// https://leetcode.com/problems/find-three-consecutive-integers-that-sum-to-a-given-number/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<long long> sumOfThree(long long num) {
      if (num % 3 != 0) {
        return {};
      }

      vector<long long> arr(3);
      arr[1] = num / 3;
      arr[0] = arr[1] - 1;
      arr[2] = arr[1] + 1;

      return arr;
    }
};

int main() {
  Solution soln;
  vector<long long> arr = soln.sumOfThree(33);

  for (int it: arr) {
    cout << it << " ";
  }

  return 0;
}
