// https://leetcode.com/problems/find-pivot-index
#include<vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int> &nums) {
      int n = nums.size();
      int sumL = 0, sumR = 0;

      for (int i = 0; i < n; i++) {
        sumL = sumR = 0;
        for (int j = 0; j < i; j++) {
          sumL += nums[j];
        }

        for (int k = i + 1; k < n; k++) {
          if (i < n) {
            sumR += nums[k];
          }
        }

//        cout << "SumL: " << sumL << " SumR: " << sumR << endl;
        if (sumL == sumR) {
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