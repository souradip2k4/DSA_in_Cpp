// https://leetcode.com/problems/rearrange-array-elements-by-sign
#include <iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int> &nums) {
      int size = nums.size();
      vector<int> pos;
      vector<int> neg;

      for (int i = 0; i < size; i++) {
        if (nums[i] >= 0) {
          pos.push_back(nums[i]);
        } else {
          neg.push_back(nums[i]);
        }
      }

      int posI = 0, negI = 0;
      for (int i = 0; i < size; i++) {
        if (i % 2 == 0) {
          nums[i] = pos[posI];
          posI++;
        } else {
          nums[i] = neg[negI];
          negI++;
        }
      }

      return nums;
    }
};

int main() {
  vector<int> nums = {3, 1, -2, -5, 2, -4};
  vector<int> nums2 = {-1, 1};
  Solution soln;

  nums2 = soln.rearrangeArray(nums2);

  for (auto elem: nums2) {
    cout << elem << ", ";
  }
}