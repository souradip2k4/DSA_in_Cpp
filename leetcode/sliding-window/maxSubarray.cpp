// https://leetcode.com/problems/maximum-subarray/description/
// 53. Maximum Subarray

using namespace std;
#include <bits/stdc++.h>

/*int maxSubArray(vector<int> &nums) {
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
}*/

vector<int> maxSubArray(vector<int> &nums) {
  if (nums.size() == 1) {
    return {nums[0]};
  }

  vector<int> maxSubArr;
  int sum = 0, maxSum = INT_MIN;

  int startI = 0, endI = 0;
  for (int i = 0; i < nums.size(); i++) {
    sum += nums[i];
    if (sum > maxSum) {
      maxSum = sum;
      endI = i;
    }

    if (sum < 0 && i <nums.size()) {
      sum = 0;
      startI = i + 1;
    }
  }

  for (int i = startI; i <= endI; i++) {
    maxSubArr.push_back(nums[i]);
  }

  cout << maxSum << endl;
  return maxSubArr;
}


// Found max subarray using two pointers approach
/*vector<int> maxSubArray(vector<int> &nums) {
  if (nums.size() == 1) {
    return {nums[0]};
  }
  vector<int> subArr;
  int sum = 0, maxSum = INT_MIN;
  int l = 0, r = 0, k = 0;
  while (r < nums.size()) {
    sum += nums[r];

    // maxSum = max(sum, maxSum);
    if (sum > maxSum) {
      maxSum = sum;
      k = r;
    }
    while (l <= r && sum < 0) {
      l = r + 1;
      sum = 0;
    }

    r++;
  }

  for (int i = l; i <=k ; i++) {
    subArr.push_back(nums[i]);
  }

  // return maxSum;
  return subArr;
}*/

int main() {
  vector<int> arr1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; //6
  vector<int> arr2 = {1}; //1
  vector<int> arr3 = {5, 4, -1, 7, 8}; // 23
  vector<int> arr4 = {-4, -3, -1, -2};

  // cout << maxSubArray(arr1) << endl;

  for (int num: maxSubArray(arr4)) {
    cout << num << " ";
  }
}
