// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
// 153. Find Minimum in Rotated Sorted Array

#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int>& arr)
{

  int smallest = INT_MAX;
  int l = 0, r = arr.size() - 1;
  int mid = l + (r - l) / 2;

  while (l <= r)
  {
    if (arr[l] <= arr[r])
    {
      return min(smallest, arr[l]);
    }
    else if (arr[l] <= arr[mid])
    {
      smallest = min(arr[l], smallest);
      l = mid + 1;
    }
    else
    {
      smallest = min(arr[mid], smallest);
      r = mid - 1;
    }

    mid = l + (r - l) / 2;
  }

  return smallest;
}

int main()
{
  vector<int> arr = { 4, 5, 6, 7, 0, 1, 2 };

  cout << findMin(arr) << endl;
}