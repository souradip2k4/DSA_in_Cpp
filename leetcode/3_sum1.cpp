// https://leetcode.com/problems/3sum

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> threeSum(vector<int> &arr) {

  vector<vector<int>> res;
  int n = arr.size();
  int i, j, k;
  sort(arr.begin(), arr.end());

  for (i = 0; i < n; i++) {

    if (i != 0 && arr[i] == arr[i - 1]) { // Removing duplicates
      continue;
    }

    j = i + 1;
    k = n - 1;

    while (j < k) {
      vector<int> triplet = {arr[i], arr[j], arr[k]};
      int sum = arr[i] + arr[j] + arr[k];

      if (sum < 0) {
        j++;

      } else if (sum > 0) {
        k--;
      } else {
        res.push_back(triplet);
        j++;
        k--;

        while (j < k && arr[j] == arr[j - 1]) { // Removing duplicates
          j++;
        }

        while (j < k && arr[k + 1] == arr[k]) { // Removing duplicates
          k--;
        }
      }
    }

  }

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