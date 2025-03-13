// https://leetcode.com/problems/count-number-of-nice-subarrays/description/
// 1248. Count Number of Nice Subarrays
// Same as max-binary-subArrays.cpp

#include <bits/stdc++.h>
using namespace std;

int atMost(vector<int> &nums, int k) {
  if (k < 0) return 0;

  int left = 0, right = 0, sum = 0, count = 0;
  while (right < nums.size()) {
    sum += nums[right] % 2;

    while (sum > k) {
      sum -= nums[left] % 2;
      left++;
    }

    count += (right - left + 1);
    right++;
  }
  return count;
}

int numberOfSubarrays(vector<int> &nums, int k) {
  return atMost(nums, k) - atMost(nums, k - 1);
  // let k = 3
  // atMost(nums, k) calculates all sub-arrays where sum <= 3
  // atMost(nums, k - 1) calculates all sub-arrays where sum <= 2
  // atMost(nums, k) - atMost(nums, k - 1) = no of sub-arrays with k = 3
}

int main() {
  vector<int> arr1 = {1, 1, 2, 1, 1};
  vector<int> arr2 = {2, 4, 6};
  vector<int> arr3 = {2, 2, 2, 1, 2, 2, 1, 2, 2, 2};


  int res1 = numberOfSubarrays(arr1, 3);
  int res2 = numberOfSubarrays(arr2, 1);
  int res3 = numberOfSubarrays(arr3, 2);

  cout << res3 << endl;
}
