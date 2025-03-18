// https://leetcode.com/problems/largest-rectangle-in-histogram/
// 84. Largest Rectangle in Histogram


// O(3n)
#include <values.h>
#include<bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int> &heights) {
  int maxArea = 0, n = heights.size();

  stack<pair<int, int> > st; // pair storing index and heights[index]
  vector<int> pse(n), nse(n);

  // O(n)
  for (int i = 0; i < n; i++) {

    while (!st.empty() && heights[i] <= st.top().second) {
      nse[st.top().first] = i;
      st.pop();
    }

    if (!st.empty()) {
      pse[i] = st.top().first;
    } else {
      pse[i] = -1;
    }

    st.push({i, heights[i]});
  }

  // Both the while loops combined has O(n)
  while (!st.empty()) {
    nse[st.top().first] = n;
    st.pop();
  }

  // O(n)
  for (int i = 0; i < n; i++) {
    maxArea = max(maxArea, heights[i] * (nse[i] - pse[i] - 1));
  }

  return maxArea;
}

int main() {
  vector<int> arr1 = {2, 1, 5, 6, 2, 3};
  vector<int> arr2 = {2, 4};

  cout << largestRectangleArea(arr1) << endl;
  cout << largestRectangleArea(arr2) << endl;
}
