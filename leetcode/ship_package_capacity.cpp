//  https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/
#include <bits/stdc++.h>

using namespace std;

int calculatedDays(vector<int> &weights, int mid) {

  int count = 1, sum = 0;
  for (int i = 0; i < weights.size(); i++) {
    sum += weights[i];
    if (sum > mid) {
      count++;
      sum = weights[i];
    }
  }

  return count;
}

int shipWithinDays(vector<int> &weights, int days) {
  int weightSum = 0;
  int result;
  int maxElem = INT_MIN;
  for (int elem: weights) {
    maxElem = max(maxElem, elem);
    weightSum += elem;
  }

  int l = maxElem, h = weightSum;

  int mid = l + (h - l) / 2;
  while (l <= h) {
    if (calculatedDays(weights, mid) <= days) {
      result = mid;
      h = mid - 1;
    } else {
      l = mid + 1;
    }
    mid = l + (h - l) / 2;
  }

  return result;
}

int main() {
  vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // days = 5
  vector<int> arr2 = {3, 2, 2, 4, 1, 4}; // days = 3

  int minCapacity = shipWithinDays(arr1, 5);

  cout << minCapacity << endl;
}