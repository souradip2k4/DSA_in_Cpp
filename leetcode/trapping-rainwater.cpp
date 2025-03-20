// https://leetcode.com/problems/trapping-rain-water/description/
// 42. Trapping Rain Water

#include<bits/stdc++.h>
using namespace std;

int trap(vector<int> &height) {
  int n = height.size(), sum = 0;;
  vector<int> prefixMax(n), suffixMax(n);

  prefixMax[0] = height[0]; // Stores the leftMax height wrt heights[i]
  suffixMax[n - 1] = height[n - 1]; // Stores the rightMax height wrt heights[i]

  for (int i = 1; i < n; i++) {
    prefixMax[i] = max(height[i], prefixMax[i - 1]);
  }

  for (int i = n - 2; i >= 0; i--) {
    suffixMax[i] = max(height[i], suffixMax[i + 1]);
  }

  for (int i = 0; i < n; i++) {
    int leftMax = prefixMax[i], rightMax = suffixMax[i];
    if (height[i] < leftMax && height[i] < rightMax) {
      // We require the minimum height between leftMax and rightMax to prevent water overflow
      sum += min(leftMax, rightMax) - height[i];
    }
  }

  return  sum;
}

int main() {
  vector<int> arr1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}, arr2 = {4, 2, 0, 3, 2, 5};
  cout << trap(arr1) << endl;
  cout << trap(arr2) << endl;
}
