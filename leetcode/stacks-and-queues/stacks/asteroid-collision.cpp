// https://leetcode.com/problems/asteroid-collision/
// 735. Asteroid Collision

#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int> &arr) {
  stack<int> st;

  st.push(arr[0]);
  for (int i = 1; i < arr.size(); i++) {
    if (arr[i] > 0) {
      st.push(arr[i]);
    } else {
      while (!st.empty() && st.top() > 0 && -arr[i] > st.top()) {
        st.pop();
      }

      if (st.empty() || st.top() < 0) {
        st.push(arr[i]);
      }

      if (!st.empty() && st.top() == -arr[i]) {
        st.pop();
      }
    }
  }

  vector<int> res(st.size());
  int i = st.size() - 1;
  while (!st.empty()) {
    res[i] = st.top();
    st.pop();
    i--;
  }

  return res;
}

int main() {
  vector<int> arr1 = {5, 10, -5}, arr2 = {8, -8}, arr3 = {10, 2, -5}, arr4 = {1, -2, -2, -2};

  vector<int> res1 = asteroidCollision(arr1);
  vector<int> res2 = asteroidCollision(arr2);
  vector<int> res3 = asteroidCollision(arr3);

  for (int num: res3) {
    cout << num << ", ";
  }
}
