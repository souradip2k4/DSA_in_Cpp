// https://leetcode.com/problems/next-permutation/
//
// 31. Next Permutation
#include <bits/stdc++.h>
using namespace std;

/*void nextPermutation(vector<int> &nums) {
  next_permutation(nums.begin(), nums.end()); // shortcut method only for c++ users
}*/

void nextPermutation(vector<int> &arr) {
  int n = arr.size();
  int index = -1;
  for (int i = n - 2; i >= 0; i--) {
    if (arr[i] < arr[i + 1]) {
      index = i;
      break;
    }
  }
  if(index == -1){
    reverse(arr.begin(), arr.end());
    return;
  }
  int minDiff = INT_MAX, j = 0;
  for (int i = index + 1; i < n; i++) {
    int diff = arr[i] - arr[index];
    if (diff < minDiff && arr[i] > arr[index]) {
      minDiff = diff;
      j = i;
    }
  }

  swap(arr[index], arr[j]);
  sort(arr.begin() + index + 1, arr.end());
}

int main() {
  vector<int> arr1 = {1, 2, 3};
  vector<int> arr2 = {3, 2, 1};
  vector<int> arr3 = {1, 1, 5};

  nextPermutation(arr3);
}
