#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement2(vector<int> nums) {
  stack<int> s;
  int n = nums.size();
  vector<int> nge(n);

  for (int i = 2 * n - 1; i >= 0; i--) {
    while (!s.empty() && s.top() <= nums[i % n]) {
      s.pop();
    }

    if (i < n) {
      if (!s.empty()) {
        nge[i] = s.top();
      } else {
        nge[i] = -1;
      }
    }

    s.push(nums[i % n]);
  }

  return nge;
}

int main() {
  vector<int> nums = {2, 10, 12, 1, 11};
  vector<int> res1 = nextGreaterElement2(nums);

  for (int num: res1) {
    cout << num << ", ";
  }
}
