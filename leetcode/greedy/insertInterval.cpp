// https://leetcode.com/problems/insert-interval/description/

// 57. Insert Interval

#include<bits/stdc++.h>
using namespace std;

/*
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

  vector<vector<int>> ans;
  int left = -1, right = -1;

  for (int i = 0; i < intervals.size(); i++) {
    if (intervals[i][1] >= newInterval[0] && left == -1) {
      left = i;
    }
    if (intervals[i][0] <= newInterval[1]) {
      right = i;
    }
  }

  for (int i = 0; i < intervals.size(); i++) {
    if (i < left || i > right) {
      ans.push_back(intervals[i]);
    }
    else if (i == left) {
      ans.push_back({ min(intervals[left][0], newInterval[0]),
                      max(intervals[right][1], newInterval[1]) });
      i = right;
    }
  }


  if (left == -1) {
    for (int i = 0; i < intervals.size(); i++) {
      ans.push_back({ intervals[i][0], intervals[i][1] });
    }
    ans.push_back(newInterval);
    sort(ans.begin(), ans.end());
  }


  return ans;
}
*/

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

  int i = 0, n = intervals.size();
  vector<vector<int>> arr;

  while (i < n && newInterval[0] > intervals[i][1]) {
    arr.push_back(intervals[i]);
    i++;
  }

  while (i < n && intervals[i][0] <= newInterval[1]) {
    newInterval[0] = min(newInterval[0], intervals[i][0]);
    newInterval[1] = max(newInterval[1], intervals[i][1]);
    i++;
  }

  arr.push_back(newInterval);

  while (i < n) {
    arr.push_back(intervals[i]);
    i++;
  }

  return arr;

}
