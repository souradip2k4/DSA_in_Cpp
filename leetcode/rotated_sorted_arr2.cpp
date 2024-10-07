// https://leetcode.com/problems/search-in-rotated-sorted-array-ii

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool search(vector<int> &arr, int target) {
      int low = 0, high = arr.size() - 1;
      int mid = low + (high - low) / 2;

      while (low <= high) {
        if (arr[mid] == target) {
          return true;
        } else if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
          low++;
          high--;
        } else if (arr[low] <= arr[mid]) { // Left half sorted

          if (arr[low] <= target && target <= arr[mid]) {
            high = mid - 1; // Target exists in sorted half
          } else {
            low = mid + 1; // Target doesn't exist in sorted half
          }
        } else {
          if (arr[mid] <= target && target <= arr[high]) {
            low = mid + 1;
          } else {
            high = mid - 1;
          }

        }

        mid = low + (high - low) / 2;
      }

      return false;
    }
};

int main() {
  Solution sol;
  vector<int> arr1 = {1, 0, 1, 1, 1};

  int ind = sol.search(arr1, 0);
  cout << "Index: " << ind << endl;
}