// https://leetcode.com/problems/rotate-array/description/

#include <bits/stdc++.h>

using namespace std;

void rotate(vector<int> &arr, int k) {

  k = k % arr.size();
  reverse(arr.begin(), arr.end());
  reverse(arr.begin(), arr.begin() + k);
  reverse(arr.begin() + k, arr.end());
}

int main() {
  vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7};
  vector<int> arr2 = {-1, -100, 3, 99};

  rotate(arr1, 3);

  for (int elem: arr1) {
    cout << elem << " ";
  }

  cout << endl;

}