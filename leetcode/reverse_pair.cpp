// https://leetcode.com/problems/reverse-pairs/description/
#include <bits/stdc++.h>

using namespace std;

int merge(vector<int> &arr, int mid, int low, int high) {
  int l = low;
  int r = mid + 1;
  vector<int> mArr;
  int count = 0;

  // Before merging the sub parts we check the no of pairs possible in this case
  for (int l = low; l <= mid; l++) {
    while (r <= high && arr[l] > 2 * arr[r]) {
      r++;
    }
    count += r - (mid + 1);
  }

  l = low, r = mid + 1;

  while (l <= mid && r <= high) {
    if (arr[l] <= arr[r]) {
      mArr.push_back(arr[l]);
      l++;
    } else {
      mArr.push_back(arr[r]);
      r++;
    }
  }
  while (l <= mid) {
    mArr.push_back(arr[l]);
    l++;
  }

  while (r <= high) {
    mArr.push_back(arr[r]);
    r++;
  }


  for (int i = low; i <= high; i++) {
    arr[i] = mArr[i - low];
  }


  return count;
}

int mergeSort(vector<int> &arr, int low, int high) {
  int count = 0;
  if (low >= high) {
    return count;
  }

  int mid = (low + high) / 2;
  count += mergeSort(arr, low, mid);
  count += mergeSort(arr, mid + 1, high);
  count += merge(arr, mid, low, high);
  return count;
}


int reversePairs(vector<int> &arr) {
  return mergeSort(arr, 0, arr.size() - 1);
}

int main() {
  vector<int> arr1 = {1, 3, 2, 3, 1};
  vector<int> arr2 = {2, 4, 3, 5, 1};

  int res = reversePairs(arr2);

  cout << res << endl;
}