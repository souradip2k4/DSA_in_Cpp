// https://leetcode.com/problems/set-matrix-zeroes/description/
// 73. Set Matrix Zeroes

#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int> > &arr) {
  vector<vector<int> > res;

  for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr[i].size(); j++) {
      if (arr[i][j] == 0) {
        res.push_back({i, j});
      }
    }
  }


  for (int k = 0; k < res.size(); k++) {
    // cout << res[k][0] << ", " << res[k][1] << endl;
    pair<int, int> p = {res[k][0], res[k][1]};
    for (int j = 0; j < arr[0].size(); j++) {
      arr[p.first][j] = 0;
    }

    for (int i = 0; i < arr.size(); i++) {
      arr[i][p.second] = 0;
    }

  }
}

int main() {
  vector<vector<int> > arr1 =
  {
    {1, 1, 1},
    {1, 0, 1},
    {1, 1, 1}
  };

  vector<vector<int> > arr2 = {
    {0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}
  };

  vector<vector<int> > arr3 = {{8, 7, 5, 3, 6, 0, 8, 8, 0}};
  setZeroes(arr3);
}
