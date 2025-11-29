#include<bits/stdc++.h>
using namespace std;

bool isNStraightHand(vector<int>& arr, int groupSize) {
  int n = arr.size();

  if (n % groupSize != 0) {
    return false;
  }

  priority_queue<int, vector<int>, greater<int>> pq;

  for (int num : arr) {
    pq.push(num);
  }

  while (!pq.empty()) {

    vector<int> duplicates;
    int start = pq.top();
    int prev = start;
    pq.pop();

    for (int i = 1; i < groupSize; i++) {
      if (pq.empty()) {
        return false;
      }

      int curr = pq.top();
      pq.pop();

      while (!pq.empty() && curr == prev) {
        duplicates.push_back(curr);
        curr = pq.top();
        pq.pop();
      }

      if (curr != (start + i)) {
        return false;
      }

      prev = curr;
    }

    for (int num : duplicates) {
      pq.push(num);
    }
  }

  return true;
}