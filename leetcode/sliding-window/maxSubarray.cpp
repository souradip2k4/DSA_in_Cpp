// https://leetcode.com/problems/maximum-subarray/description/
// 53. Maximum Subarray

using namespace std;
#include <bits/stdc++.h>

int maxSubArray(vector<int> &nums) {
  if (nums.size() == 1) {
    return nums[0];
  }
  int sum = 0, maxSum = INT_MIN;
  for (int i = 0; i < nums.size(); i++) {
    sum += nums[i];

    maxSum = max(sum, maxSum);
    if (sum < 0) {
      sum = 0;
    }
  }

  return maxSum;
}

int main() {
  vector<int> arr1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; //6
  vector<int> arr2 = {1}; //1
  vector<int> arr3 = {5, 4, -1, 7, 8}; // 23

  cout << maxSubArray(arr1) << endl;
}
