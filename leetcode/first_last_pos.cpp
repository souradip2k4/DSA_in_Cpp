// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
  vector<int> searchRange(vector<int>& arr, int target) {
    vector<int> res = { -1, -1 };
    int l = 0, h = arr.size() - 1;
    int mid = l + (h - l) / 2;
    if (arr.empty()) {
      return res;
    }

    vector<int> leftPart;

    while (l <= h) {
      if (target == arr[mid]) {
        // Separating the left half of the array for finding leftmost occurrence of target
        leftPart.push_back(l);
        leftPart.push_back(mid - 1);

        res[0] = res[1] = mid;
        l = mid + 1; // To find the rightmost occurrence of target
      }
      else if (target > arr[mid]) {
        l = mid + 1;
      }
      else {
        h = mid - 1;
      }

      mid = l + (h - l) / 2;
    }


    if (!leftPart.empty()) {
      l = leftPart[0], h = leftPart[1];
      mid = l + (h - l) / 2;
      while (l <= h) {
        if (target == arr[mid]) {

          res[0] = mid;
          h = mid - 1;

        }
        else if (target > arr[mid]) {
          l = mid + 1;
        }
        else {
          h = mid - 1;
        }

        mid = l + (h - l) / 2;
      }
    }

    return res;
  }
};

int main() {
  Solution soln;
  vector<int> arr1 = { 5, 7, 8, 8, 8, 8, 8 };
  vector<int> arr2 = { 5, 7, 7, 8, 8, 10 };

  vector<int> res = soln.searchRange(arr1, 8);

  cout << res[0] << ", " << res[1] << endl;
}