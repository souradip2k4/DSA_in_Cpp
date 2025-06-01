// https://leetcode.com/problems/single-number-iii/description/?envType=problem-list-v2&envId=a0pb9aqc
// 260. Single Number III

#include<bits/stdc++.h>
using namespace std;

vector<int> singleNumber(vector<int> &nums) {
  long x = 0;

  for (int i = 0; i < nums.size(); i++) {
    x ^= nums[i];
  }

  int rightestSetBit = (x & (x - 1)) ^ x;
  int b1 = 0, b2 = 0;

  for (int i = 0; i < nums.size(); i++) {
    if ((nums[i] & rightestSetBit) > 0) {
      b1 ^= nums[i];
    } else {
      b2 ^= nums[i];
    }
  }

  return {b1, b2};
}

int main() {
  vector<int> arr1 = {1, 2, 1, 3, 2, 5}; // [3,5]
  vector<int> arr2 = {-1, 0}; // [-1,0]

  vector<int> res = singleNumber(arr2);

  cout << res[0] << " " << res[1] << endl;
}
