// https://leetcode.com/problems/pascals-triangle/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> generate(int numRows) {
  vector<vector<int>> arr;
  if (numRows == 1) {
    return {{1}};
  }

  arr.push_back({1});

  int i = 1;

    while (i < numRows) {
      vector<int> row(i + 1, 1);
      for (int j = 1; j < i; j++) {
        row[j] = arr[i - 1][j - 1] + arr[i - 1][j];
      }

      arr.push_back(row);
      i++;
    }


  return arr;
}

int main() {
  vector<vector<int>> result = generate(5);
  for (const auto &row: result) {
    for (int num: row) {
      cout << num << " ";
    }
    cout << endl;
  }

}