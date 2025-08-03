// https://leetcode.com/problems/spiral-matrix/
// 54. Spiral Matrix

#include <bits/stdc++.h>
using namespace std;

/*vector<int> spiralOrder(vector<vector<int> > &matrix) {
  pair<int, int> topL = {0, 0}, topR = {0, matrix[0].size() - 1}, bottomL = {matrix.size() - 1, 0}, bottomR = {
    matrix.size() - 1, matrix[0].size() - 1
  };

  vector<int> res;
  int arrSize = matrix.size() * matrix[0].size();

  while (true) {
    for (int i = topL.second; i <= topR.second; i++) {
      res.push_back(matrix[topL.first][i]);
    }
    topL = {topL.first + 1, topL.second};
    topR = {topR.first + 1, topR.second};

    for (int i = topR.first; i <= bottomR.first; i++) {
      res.push_back(matrix[i][topR.second]);
    }

    topR = {topR.first, topR.second - 1};
    bottomR = {bottomR.first, bottomR.second - 1};

    for (int i = bottomR.second; i >= bottomL.second; i--) {
      res.push_back(matrix[bottomL.first][i]);
    }

    bottomL = {bottomL.first - 1, bottomL.second};
    bottomR = {bottomR.first - 1, bottomR.second};

    for (int i = bottomL.first; i >= topL.first; i--) {
      res.push_back(matrix[i][bottomL.second]);
    }

    topL = {topL.first, topL.second + 1};
    bottomL = {bottomL.first, bottomL.second + 1};

    if (res.size() == arrSize) {
      break;
    }
  }

  return res;
}
*/


vector<int> spiralOrder(vector<vector<int> > &matrix) {
  int top = 0, bottom = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;
  vector<int> res;

  while (top <= bottom && left <= right) {
    for (int j = left; j <= right; j++) {
      res.push_back(matrix[top][j]);
    }
    top++;


    for (int i = top; i <= bottom; i++) {
      res.push_back(matrix[i][right]);
    }
    right--;


    if (top <= bottom) {
      for (int j = right; j >= left; j--) {
        res.push_back(matrix[bottom][j]);
      }

      bottom--;
    }


    if (left <= right) {
      for (int i = bottom; i >= top; i--) {
        res.push_back(matrix[i][left]);
      }
      left++;
    }
  }

  return res;
}

int main() {
  vector<vector<int> > arr1 =
  {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 16}
  };
  vector<vector<int> > arr2 =
  {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
  };

  vector<int> res = spiralOrder(arr2);

  for (int num: res) {
    cout << num << ", ";
  }
}
