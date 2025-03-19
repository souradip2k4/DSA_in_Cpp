// https://leetcode.com/problems/largest-rectangle-in-histogram/
// 84. Largest Rectangle in Histogram

#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int> &heights) {
  int maxArea = 0, n = heights.size();

  // Stack stores {index, height} to find next and previous smaller elements efficiently
  stack<pair<int, int>> st;
  vector<int> pse(n), nse(n);

  // Finding Next Smaller Element (NSE) and Previous Smaller Element (PSE) in one pass
  for (int i = 0; i < n; i++) {
    // Pop elements from the stack until we find a smaller element
    while (!st.empty() && heights[i] <= st.top().second) {
      nse[st.top().first] = i;  // Current element is the next smaller for top of stack
      st.pop();
    }

    // If stack is not empty, top of the stack is the previous smaller element
    if (!st.empty()) {
      pse[i] = st.top().first;
    } else {
      pse[i] = -1;  // If no smaller element exists, set to -1
    }

    // Push the current element index and height onto the stack
    st.push({i, heights[i]});
  }

  // Assign NSE = n for remaining elements in the stack (since no smaller element exists)
  while (!st.empty()) {
    nse[st.top().first] = n;
    st.pop();
  }

  // Compute the maximum area using height and width calculated from NSE and PSE
  for (int i = 0; i < n; i++) {
    int width = nse[i] - pse[i] - 1;  // Width of the largest rectangle with height[i]
    maxArea = max(maxArea, heights[i] * width);
  }

  return maxArea;
}

int main() {
  vector<int> arr1 = {2, 1, 5, 6, 2, 3};
  vector<int> arr2 = {2, 4};

  cout << largestRectangleArea(arr1) << endl; // Expected output: 10
  cout << largestRectangleArea(arr2) << endl; // Expected output: 4
}
