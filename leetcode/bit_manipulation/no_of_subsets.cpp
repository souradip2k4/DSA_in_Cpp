// https://leetcode.com/problems/subsets/description/
// 78. Subsets
#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > subsets(vector<int>& nums) {
  int n = nums.size();
  vector<vector<int>> res;
  for (int i = 0; i < (1 << n); i++) {
    vector<int> arr;

    for (int j = 0; j < n; j++) {
      if ((i & (1 << j)) != 0) {
        arr.push_back(nums[j]);
      }
    }
    res.push_back(arr);
  }

  return res;
}

int main() {
  vector<int> a = { 1, 2, 3 };
  vector<int> b = { 0 };

  vector<vector<int> > res = subsets(a);

  for (auto nums : res) {
    for (int num : nums) {
      cout << num << ", ";
    }
    cout << endl;
  }

  cout << res.size() << endl;
}
