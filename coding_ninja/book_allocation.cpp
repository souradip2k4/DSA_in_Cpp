// https://www.naukri.com/code360/problems/allocate-books_1090540
#include <bits/stdc++.h>

using namespace std;

int calculateStudents(vector<int> &arr, int mid) {
  int sum = 0, count = 1;

  for (int i = 0; i < arr.size(); i++) {
    sum += arr[i];
    if (sum > mid) {
      count++;
      sum = arr[i];
    }
  }

  return count;
}

int findPages(vector<int> &arr, int m) {
  int n = arr.size();
  int maxElem = INT_MIN, maxSum = 0;
  if (m > n) {
    return -1;
  }

  for (int elem: arr) {
    maxElem = max(elem, maxElem);
    maxSum += elem;
  }

  int l = maxElem, h = maxSum;
  int result = h;
  int mid = l + (h - l) / 2;

  while (l <= h) {
    if (calculateStudents(arr, mid) <= m) {
      result = mid;
      h = mid - 1;
    } else {
      l = mid + 1;
    }

    mid = l + (h - l) / 2;
  }

  return result;
}

int main() {
  vector<int> arr1 = {12, 34, 67, 90}; // m = 2
  vector<int> arr2 = {25, 46, 28, 49, 24}; // m = 4

  int minPages = findPages(arr1, 2);

  cout << minPages << endl;
}