// https://leetcode.com/problems/sum-of-subarray-minimums/description/
// 907. Sum of Subarray Minimums

#include <values.h>
#include<bits/stdc++.h>
using namespace std;

vector<int> previousSmallerElement(vector<int> &arr) {
  int n = arr.size();
  vector<int> pse(n);
  stack<int> st;

  for (int i = 0; i < n; i++) {
    // Use < in PSE to ensure the closest strictly smaller element is stored.
    // {3, 3, 1, 2} PSE of arr[1] = 3 should not be -1. It should be the index of the duplicate element in the left
    while (!st.empty() && arr[i] < arr[st.top()]) {
      st.pop();
    }

    pse[i] = !st.empty() ? st.top() : -1;

    st.push(i);
  }

  return pse;
}

vector<int> nextSmallerElement(vector<int> &arr) {
  int n = arr.size();
  vector<int> nse(n);
  stack<int> st;

  for (int i = n - 1; i >= 0; i--) {
    // Use <= in NSE to correctly remove duplicates and get the next valid smaller element.
    while (!st.empty() && arr[i] <= arr[st.top()]) {
      st.pop();
    }

    nse[i] = !st.empty() ? st.top() : n;

    st.push(i);
  }

  return nse;
}

int sumSubarrayMins(vector<int> &arr) {
  vector<int> pse = previousSmallerElement(arr);
  vector<int> nse = nextSmallerElement(arr);
  int sum = 0;
  const int MOD = 10e9 + 7;
  for (int i = 0; i < arr.size(); i++) {
    long long left = (i - pse[i]);
    long long right = (nse[i] - i);
    long long product = (left * right) % MOD;
    long long contrib = (product * arr[i])%MOD;
    sum = (sum + contrib) % MOD;
  }

  return sum;
}

int main() {
  vector<int> arr1 = {3, 1, 2, 4};
  vector<int> arr2 = {11, 81, 94, 43, 3};

  cout << sumSubarrayMins(arr1) << endl;
  cout << sumSubarrayMins(arr2) << endl;
}
