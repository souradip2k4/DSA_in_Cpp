// https://leetcode.com/problems/sort-colors/description/

#include<bits/stdc++.h>

using namespace std;
// Dutch National Flag algorithm
void sortColors(vector<int> &arr) {

  // low -> 0, mid -> 1, high -> 1
  int l = 0, mid = 0, h = arr.size() - 1;

  while (mid <= h) {
    if (arr[mid] == 0) {
      swap(arr[l], arr[mid]);
      l++;
      mid++;
    } else if (arr[mid] == 1) {
      mid++;
    } else {
      swap(arr[mid], arr[h]);

      h--;
    }
  }
}

int main() {

  vector<int> arr1 = {2, 0, 2, 1, 1, 0};
  vector<int> arr2 = {2, 0, 1};
  sortColors(arr1);

}