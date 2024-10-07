// https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int> &arr) {
      int l = 0, h = arr.size() - 1;
      int n = arr.size();
      int mid = l + (h - l) / 2;

      if (n == 1) {
        return 0;
      } else if (arr[0] > arr[1]) {
        return 0;
      } else if (arr[n - 1] > arr[n - 2]) {
        return n - 1;
      }

      while (l <= h) {

        if (mid - 1 >= 0 && mid + 1 < n && arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
          return mid;
        } else if (mid - 1 >= 0 && arr[mid - 1] > arr[mid]) {
          h = mid - 1;
        } else if (mid + 1 < n && arr[mid] < arr[mid + 1]) {
          l = mid + 1;
        }

        mid = l + (h - l) / 2;
      }

      return -1;
    }
};

// start = 0, 1, 2, 3
// mid = 1, 2, 2, 3

int main() {
  Solution soln;
  vector<int> arr = {3, 5, 3, 2, 0};
  int result = soln.peakIndexInMountainArray(arr);

  cout << "Index of largest element in array: " << result << endl;
  return 0;
}