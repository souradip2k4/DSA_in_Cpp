// https://leetcode.com/problems/search-insert-position/
#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
      int start = 0, end = nums.size() - 1;
      int mid = start + (end - start) / 2;

      while (end >= start) {
        if (target < nums[0]) {
          return 0;
        } else if (target > nums[nums.size() - 1]) {
          return end + 1;
        }

        if (nums[mid] == target || (target > nums[mid - 1] && target < nums[mid])) {
          return mid;
        }

        if (nums[mid] > target) {
          end = mid - 1;
        } else {
          start = mid + 1;
        }

        mid = start + (end - start) / 2;
      }
      return mid;
    }
};

int main() {
  vector<int> arr = {1, 3};
  Solution soln;
  int position = soln.searchInsert(arr, 2);

  cout << position << endl;
  return 0;
}