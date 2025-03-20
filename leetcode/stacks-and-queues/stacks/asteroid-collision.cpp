// https://leetcode.com/problems/asteroid-collision/
// 735. Asteroid Collision

#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int> &arr) {
  stack<int> st;

  // Push the first asteroid into the stack
  st.push(arr[0]);

  // Process the remaining asteroids
  for (int i = 1; i < arr.size(); i++) {
    // [8,-8]
    if (arr[i] > 0) {
      // If the asteroid is moving right, push it onto the stack
      st.push(arr[i]);
    } else {
      // If the asteroid is moving left, handle possible collisions
      while (!st.empty() && st.top() > 0 && -arr[i] > st.top()) {
        // Right-moving asteroid is smaller, destroy it
        st.pop();
      }

      // If the stack is empty or the current asteroid arr[i] is also moving left, push the new asteroid
      if (st.empty() || st.top() < 0) {
        st.push(arr[i]);
      }

      // If both asteroids have the same size but opposite directions, both get destroyed
      if (st.top() == -arr[i]) {
        st.pop();
      }
    }
  }

  // Store remaining asteroids in the result vector
  vector<int> res(st.size());
  int i = st.size() - 1;

  // Transfer stack elements to the result vector in correct order
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
  vector<int> res4 = asteroidCollision(arr4);

  for (int num: res2) {
    cout << num << ", ";
  }
}
