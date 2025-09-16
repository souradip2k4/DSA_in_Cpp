// https://leetcode.com/problems/non-overlapping-intervals/description/
// 435. Non-overlapping Intervals

#include<bits/stdc++.h>
using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals) {

  // In greedy job problems we need to sort on basis of earliest finish so we need to sort on basis of 1th index
  sort(intervals.begin(), intervals.end(), [](vector<int>& a1, vector<int>& a2) {
    return a1[1] > a2[1];
    });

  int minCnt = 0;
  int prevEnd = intervals[0][1];
  for (int i = 1; i < intervals.size(); i++) {
    if (intervals[i][0] < prevEnd) {
      minCnt++;
    }
    else {
      prevEnd = intervals[i][1];
    }
  }

  return minCnt;

}

int main() {
  int n;
  cin >> n;

  vector<vector<int>> arr(n);

  for (int i = 0; i < n; i++) {
    pair<int, int> p;

    cin >> p.first >> p.second;
    arr[i].push_back(p.first);
    arr[i].push_back(p.second);
  }

  cout << eraseOverlapIntervals(arr) << endl;
}