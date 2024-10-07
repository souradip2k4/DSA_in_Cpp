// https://leetcode.com/problems/search-in-rotated-sorted-array/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int> &arr, int target) {
      int l = 0, h = arr.size() - 1;
      int mid = l + (h - l) / 2;

      while (l <= h) {
        if (arr[mid] == target) {
          return mid;
        } else if (arr[l] <= arr[mid]) { // Left half sorted

          if (arr[l] <= target && target <= arr[mid]) {
            h = mid - 1; // Target exists in sorted half
          } else {
            l = mid + 1;
          }
        }

        if(arr[h] > arr[mid]){
          if (arr[mid] <= target && target <= arr[h]) {
            l = mid + 1;
          } else {
            h = mid - 1;
          }

        }

        mid = l + (h - l) / 2;
      }

      return -1;
    }
};

int main() {
  Solution sol;
  vector<int> arr1 = {4, 5, 6, 7, 0, 1, 2};

  int ind = sol.search(arr1, 0);
  cout << "Index: " << ind << endl;
}