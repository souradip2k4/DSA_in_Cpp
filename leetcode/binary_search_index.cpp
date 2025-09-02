// https://leetcode.com/problems/search-insert-position/
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int searchInsert(vector<int>& arr, int target)
  {
    if (target <= arr[0]) {
      return 0;
    }
    else if (target > arr[arr.size() - 1]) {
      return arr.size();
    }

    int l = 0, r = arr.size() - 1;
    int mid = l + (r - l) / 2;

    while (l <= r) {

      if ((mid - 1) >= 0 && arr[mid - 1] < target && target <= arr[mid])
      {
        return mid;
      }
      else if (arr[mid] < target)
      {
        r = mid - 1;
      }
      else if (arr[mid] > target)
      {
        l = mid + 1;
      }

      mid = l + (r - l) / 2;
    }

    return -1;
  }
};

int main()
{
  vector<int> arr = { 1, 3 };
  Solution soln;
  int position = soln.searchInsert(arr, 2);

  cout << position << endl;
  return 0;
}