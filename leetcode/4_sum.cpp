// https://leetcode.com/problems/4sum/description/
#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> fourSum(vector<int> &arr, int target) {
  int i, j, k, l, n = arr.size();
  vector<vector<int>> res;

  if (n < 4) {
    return {};
  }

  sort(arr.begin(), arr.end());
  for (i = 0; i < n - 3; i++) {
    if (i > 0 && arr[i - 1] == arr[i]) {
      continue;
    }

    for (j = i + 1; j < n - 2; j++) {
      if (j > i + 1 && arr[j - 1] == arr[j]) {
        continue;
      }

      k = j + 1;
      l = n - 1;
      while (k < l) {
        vector<int> quadPair = {arr[i], arr[j], arr[k], arr[l]};
        long sum = (long) arr[i] + (long) arr[j] + (long) arr[k] + (long) arr[l];

        if (sum > target) {
          l--;
        } else if (sum < target) {
          k++;
        } else {
          res.push_back(quadPair);
          k++;
          l--;

          while (k < l && arr[l + 1] == arr[l]) {
            l--;
          }

          while (k < l && arr[k - 1] == arr[k]) {
            k++;
          }
        }

      }
    }
  }

  return res;
}

int main() {
  vector<int> arr1 = {1, 0, -1, 0, -2, 2}; // t = 0
  vector<int> arr2 = {2, 2, 2, 2, 2}; // t = 8
  vector<int> arr3 = {-2, -1, -1, 1, 1, 2, 2}; // t = 0


  vector<vector<int>> res = fourSum(arr3, 0);

  for (auto i: res) {
    for (int elem: i) {
      cout << elem << " ";
    }
    cout << endl;
  }
}