// 78. Subsets
// https://leetcode.com/problems/subsets/description/

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> &nums, int index, vector<vector<int> > &res, vector<int> &subArr) {
  if (index == nums.size()) {
    res.push_back(subArr);
    return;
  }

  subArr.push_back(nums[index]);
  dfs(nums, index + 1, res, subArr);

  subArr.pop_back();
  dfs(nums, index + 1, res, subArr);
}

vector<vector<int> > subsets(vector<int> &nums) {
  vector<vector<int> > res;
  vector<int> subArr;
  dfs(nums, 0, res, subArr);
  return res;
}

int main() {
  vector<int> arr1 = {1, 2, 3};
  vector<vector<int> > res = subsets(arr1);
  for (auto &it: res) {
    for (int num: it) {
      cout << " " << num << ",";
    }
    cout << endl;
  }
}