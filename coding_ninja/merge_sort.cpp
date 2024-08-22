// https://www.naukri.com/code360/problems/merge-sort_920442
#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &arr, int mid, int low, int high) {
  int left = low;
  int right = mid + 1;
  vector<int> mArr;

  while (left <= mid && right <= high) {
    if (arr[left] <= arr[right]) {
      mArr.push_back(arr[left]);
      left++;
    } else {
      mArr.push_back(arr[right]);
      right++;
    }
  }
  while (left <= mid) {
    mArr.push_back(arr[left]);
    left++;
  }

  while (right <= high) {
    mArr.push_back(arr[right]);
    right++;
  }

  for (int i = low; i <= high; i++) {
    arr[i] = mArr[i - low];
  }
}

void mergeSort(vector<int> &arr, int low, int high) {
  if (low == high) {
    return;
  }

  int mid = (low + high) / 2;
  mergeSort(arr, low, mid);
  mergeSort(arr, mid + 1, high);
  merge(arr, mid, low, high);
}

int main () {
  vector<int> arr = {7, 6, 9, 2, 5, 2, 9};

  mergeSort(arr, 0, arr.size() - 1);
  for(auto elem: arr){
    cout << elem << ", ";
  }

  return 0;
}