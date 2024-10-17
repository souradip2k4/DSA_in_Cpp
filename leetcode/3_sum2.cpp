// https://leetcode.com/problems/3sum

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> threeSum(vector<int> &arr) {

  vector<vector<int>> res;
  int n = arr.size();
  int i, j;

  set<vector<int>> hashSet;

  for (i = 0; i < n - 1; i++) {
    set<int> st;
    j = i + 1;

    while (j < n) {
      vector<int> triplet;
      int sum = -(arr[i] + arr[j]);


      if (st.find(sum) != st.end()) {
        triplet = {arr[i], arr[j], sum};

        sort(triplet.begin(), triplet.end());
        hashSet.insert(triplet);
      }

      st.insert(arr[j]);
      j++;
    }
  }

  res = {hashSet.begin(), hashSet.end()};

  return res;
}

int main() {
  vector<int> arr1 = {-1, 0, 1, 2, -1, -4}; // {-4, -1, -1, 0, 2 }
  vector<vector<int>> res = threeSum(arr1);

  for (auto i: res) {
    for (int elem: i) {
      cout << elem << " ";
    }
    cout << endl;
  }
}