// https://leetcode.com/problems/find-pivot-index/?source=submission-noac
#include<vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int> &nums) {
      int len = nums.size();
      vector<int> prefix(len + 1, 0), postfix(len + 1, 0);

      for (int i = 0; i < len - 1; i++) {
        prefix[i + 1] = prefix[i] + nums[i];
      }

      for (int i = len - 1; i >= 0; i--) {
        postfix[i] = postfix[i + 1] + nums[i];
      }

      for (int i = 0; i < len; i++) {
        if (prefix[i] == postfix[i + 1]) {
          return i;
        }
      }
      return -1;
    }
};

int main() {

  Solution soln;
  vector<int> nums = {1, 7, 3, 6, 5, 6};

  int index = soln.pivotIndex(nums);

  cout << "Pivot index: " << index << endl;
}