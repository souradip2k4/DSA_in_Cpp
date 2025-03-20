// https://leetcode.com/problems/sum-of-subarray-ranges/description/
// 2104. Sum of Subarray Ranges

#include<bits/stdc++.h>
using namespace std;

vector<int> previousSmallest(vector<int> &nums) {
  int n = nums.size();
  vector<int> pse(n);
  stack<int> st;

  for (int i = 0; i < n; i++) {
    while (!st.empty() && nums[i] < nums[st.top()]) {
      st.pop();
    }

    pse[i] = !st.empty() ? st.top() : -1;

    st.push(i);
  }

  return pse;
}

vector<int> nextSmallest(vector<int> &nums) {
  int n = nums.size();
  vector<int> nse(n);
  stack<int> st;

  for (int i = n - 1; i >= 0; i--) {
    while (!st.empty() && nums[i] <= nums[st.top()]) {
      st.pop();
    }

    nse[i] = !st.empty() ? st.top() : n;
    st.push(i);
  }

  return nse;
}

vector<int> previousGreatest(vector<int> &nums) {
  int n = nums.size();
  vector<int> pge(n);
  stack<int> st;

  for (int i = 0; i < n; i++) {
    while (!st.empty() && nums[i] > nums[st.top()]) {
      st.pop();
    }

    pge[i] = !st.empty() ? st.top() : -1;
    st.push(i);
  }

  return pge;
}

vector<int> nextGreatest(vector<int> &nums) {
  int n = nums.size();
  vector<int> nge(n);
  stack<int> st;

  for (int i = n - 1; i >= 0; i--) {
    while (!st.empty() && nums[i] >= nums[st.top()]) {
      st.pop();
    }

    nge[i] = !st.empty() ? st.top() : n;
    st.push(i);
  }

  return nge;
}

long long subArrayRanges(vector<int> &nums) {
  vector<int> pse = previousSmallest(nums);
  vector<int> nse = nextSmallest(nums);
  vector<int> pge = previousGreatest(nums);
  vector<int> nge = nextGreatest(nums);
  long long sum = 0;
  for (int i = 0; i < nums.size(); i++) {
    int minElemSubarrCnt = (i - pse[i]) * (nse[i] - i);
    int maxElemSubarrCnt = (i - pge[i]) * (nge[i] - i);
    sum += (long long) nums[i] * (maxElemSubarrCnt - minElemSubarrCnt);
  }

  return sum;
}

int main() {
  vector<int> arr1 = {1, 2, 3}, arr2 = {1, 3, 3}, arr3 = {4, -2, -3, 4, 1};

  cout << subArrayRanges(arr1) << endl;
  cout << subArrayRanges(arr2) << endl;
  cout << subArrayRanges(arr3) << endl;
}
