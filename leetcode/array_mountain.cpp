// https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int> &arr) {
      int start = 0, end = arr.size() - 1, index = 0;
      int mid = start + (end - start) / 2;

      while (end > start) {
        if (arr[mid] < arr[mid + 1]) {
          start = mid + 1;
          index = start;
        } else if (arr[mid] > arr[mid + 1]) {
          end = mid;
        }


        mid = start + (end - start) / 2;
      }

      return index;
    }
};

// start = 0, 1, 2, 3
// mid = 1, 2, 2, 3

int main() {
  Solution soln;
  vector<int> arr = {0, 2, 4, 6};
  int result = soln.peakIndexInMountainArray(arr);

  cout << "Index of largest element in array: " << result << endl;
  return 0;
}