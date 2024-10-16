// https://www.naukri.com/code360/problems/number-of-inversions_6840276
#include<bits/stdc++.h>

using namespace std;

int merge(vector<int> &arr, int mid, int low, int high) {
  int l = low;
  int r = mid + 1;
  vector<int> mArr;
  int count = 0;

  while (l <= mid && r <= high) {
    if (arr[l] <= arr[r]) {
      mArr.push_back(arr[l]);
      l++;
    } else {
      count += mid - l + 1;
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

int numberOfInversions(vector<int> &arr, int n) {
  return mergeSort(arr, 0, n - 1);
}

int main() {

  vector<int> arr1 = {4, 3, 2, 1};
  vector<int> arr2 = {1, 20, 6, 4, 5};

  cout << numberOfInversions(arr2, 6) << endl;
}