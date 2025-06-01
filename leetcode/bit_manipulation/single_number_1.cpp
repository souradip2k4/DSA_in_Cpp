// https://leetcode.com/problems/single-number/description/
// 136. Single Number

#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int> &nums) {
  int ans = 0;
  for (int num: nums) {
    ans = ans ^ num;
  }


  return ans;
}

int main() {
  vector<int> arr1 = {4, 1, 2, 1, 2};
  vector<int> arr2 = {1};
  cout << singleNumber(arr2) << endl;
}
