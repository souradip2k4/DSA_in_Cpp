// https://leetcode.com/problems/two-sum/
// 1. Two Sum

#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target) {
  unordered_map<int, int> uMap;


  for (int i = 0; i < nums.size(); i++) {
    int diff = target - nums[i];

    if (uMap.find(diff) != uMap.end()) {
      return {uMap[diff], i};
    } else {
      uMap.insert({nums[i], i});
    }
  }

  return {-1, -1};
}

// This will work only if
/*vector<int> twoSum(vector<int> &nums, int target) {
  sort(nums.begin(), nums.end());

  int l = 0, r = nums.size() - 1;
  while (l < r) {
    if (nums[l] + nums[r] == target) {
      return {nums[l], nums[r]};
    } else if (nums[l] + nums[r] < target) {
      l++;
    } else {
      r--;
    }
  }

  return {-1, -1};
}*/

int main() {
  vector<int> arr = {2, 7, 11, 15};

  vector<int> ans = twoSum(arr, 9);

  cout << ans[0] << " " << ans[1];
}
