// https://leetcode.com/problems/binary-subarrays-with-sum/description/
// 930. Binary Subarrays With Sum

#include <bits/stdc++.h>
using namespace std;

int atMost(vector<int> &nums, int goal) {
  if (goal < 0) return 0;

  int left = 0, right = 0, sum = 0, count = 0;
  while (right < nums.size()) {
    sum += nums[right];

    while (sum > goal) {
      sum -= nums[left];
      left++;
    }

    count += (right - left + 1);
    right++;
  }
  return count;
}

int numSubarraysWithSum(vector<int> &nums, int goal) {
  return atMost(nums, goal) - atMost(nums, goal - 1);
}

int main() {
  vector<int> arr1 = {1, 0, 1, 0, 1};
  vector<int> arr2 = {0, 0, 0, 0, 0};

  int res1 = numSubarraysWithSum(arr1, 2);
  int res2 = numSubarraysWithSum(arr2, 0);

  cout << res1 << endl;
}
