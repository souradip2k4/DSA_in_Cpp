// https://leetcode.com/problems/max-consecutive-ones-iii/
// 1004. Max Consecutive Ones III

#include <bits/stdc++.h>
using namespace std;

int longestOnes(vector<int> &nums, int k) {
  int arr[] = {0, 0};
  int l = 0, r = 0, maxL = 0;
  while (r < nums.size()) {
    arr[nums[r]]++;
    if (arr[0] > k) {
      arr[nums[l]]--;
      l++;
    }

    maxL = max(maxL, r - l + 1);
    r++;
  }

  return maxL;
}

int main() {
  vector<int> arr1 = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0},
      arr2 = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};

  cout << longestOnes(arr1, 2) << endl;
  cout << longestOnes(arr2, 3) << endl;
}
