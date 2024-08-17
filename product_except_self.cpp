// https://leetcode.com/problems/product-of-array-except-self/description/
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {

      int size = nums.size();
      int prod = 1, checked = 0, count = 0;
      for (int i = 0; i < size; i++) {
        if (nums[i] != 0) {
          prod = prod * nums[i];
        } else {
          checked = 1;
          count++;
        }
      }

      for (int i = 0; i < size; i++) {
        if (nums[i] == 0 && checked == 1) {
          if (prod == 1 && nums[i] == 1 && count < size) { // [1, 0]
            nums[i] = 1;
          } else if (count > 1) { // [0, 4, 0]
            nums[i] = 0;
          } else { // [4, 1, 0, 2] Only one 0 in the array
            nums[i] = prod;
          }
        } else if (nums[i] != 0 && checked == 0) { // [1, 4 ,6 ,7]

          nums[i] = prod / nums[i];
        } else { // [4, 1, 0 ,2]
          nums[i] = 0;
        }
      }

      return nums;
    }
};

int main() {
  vector<int> nums = {0, 4, 0};
  Solution soln;

  vector<int> result = soln.productExceptSelf(nums);

  for (auto it: result) {
    cout << it << " ";
  }

}