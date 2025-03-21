// https://leetcode.com/problems/next-greater-element-i/description/
// 496. Next Greater Element I

#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
  stack<int> s1;
  vector<int> nge(nums2.size());

  for (int i = nums2.size() - 1; i >= 0; i--) {
    while (!s1.empty() && nums2[i] > s1.top()) {
      s1.pop();
    }

    if (!s1.empty()) {
      nge[i] = s1.top();
    } else {
      nge[i] = -1;
    }
    s1.push(nums2[i]);
  }

  vector<int> arr2;
  for (int it: nums1) {
    for (int i = 0; i < nums2.size(); i++) {
      if (it == nums2[i]) {
        arr2.push_back(nge[i]);
      }
    }
  }

  return arr2;
}

int main() {
  vector<int> nums1 = {4, 1, 2}, nums2 = {1, 3, 4, 2};

  vector<int> res1 = nextGreaterElement(nums1, nums2);

  for (int num: res1) {
    cout << num << ", ";
  }
}
