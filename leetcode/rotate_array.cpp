// https://leetcode.com/problems/rotate-array/description/

#include <bits/stdc++.h>

using namespace std;

void rotate(vector<int> &arr, int k) {

  k = k % arr.size(); // if k > size of arr[] then reverse will be done on basis of this
  reverse(arr.begin(), arr.end());
  reverse(arr.begin(), arr.begin() + k);
  reverse(arr.begin() + k, arr.end());
}

int main() {
  vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7}; // k = 3
  vector<int> arr2 = {-1, -100, 3}; // k = 4

  rotate(arr2, 4);

  for (int elem: arr2) {
    cout << elem << " ";
  }

  cout << endl;
}