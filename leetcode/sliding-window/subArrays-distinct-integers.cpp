// https://leetcode.com/problems/subarrays-with-k-different-integers/description/
// 992. Subarrays with K Different Integers

#include<bits/stdc++.h>
using namespace std;

int atMost(vector<int> &nums, int k) {
  if (k <= 0) return 0;
  int l = 0, r = 0, count = 0;
  unordered_map<int, int> uMap;

  while (r < nums.size()) {
    uMap[nums[r]]++;

    while (uMap.size() > k) {
      uMap[nums[l]]--;

      if (uMap[nums[l]] == 0) {
        uMap.erase(nums[l]);
      }
      l++;
    }

    count += r - l + 1;
    r++;
  }

  return count;
}

int subarraysWithKDistinct(vector<int> &nums, int k) {
  return atMost(nums, k) - atMost(nums, k - 1);
}

int main() {
  vector<int> arr1 = {1, 2, 1, 2, 3};
  vector<int> arr2 = {1, 2, 1, 3, 4};

  int res1 = subarraysWithKDistinct(arr1, 2);
  int res2 = subarraysWithKDistinct(arr2, 3);

  cout << res1 << endl;
}
