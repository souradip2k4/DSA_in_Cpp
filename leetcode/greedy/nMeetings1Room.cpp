// https://leetcode.com/problems/maximum-length-of-pair-chain/
// 646. Maximum Length of Pair Chain

#include<bits/stdc++.h>
using namespace std;

struct meeting {
  int start;
  int end;
  int pos;
};

bool comparator(const meeting& m1, const meeting& m2) {
  if (m1.end < m2.end) return true;
  else if (m1.end > m2.end) return false;
  else if (m1.pos < m2.pos) return true;
  else return false;
}

int findLongestChain(vector<vector<int>>& pairs) {
  int n = pairs.size();
  vector<meeting> meet(n);

  for (int i = 0; i < n; i++) {
    meet[i].start = pairs[i][0];
    meet[i].end = pairs[i][1];
    meet[i].pos = i;
  }

  sort(meet.begin(), meet.end(), comparator);

  int limit = meet[0].end;
  int cnt = 1;

  for (int i = 1; i < n; i++) {
    if (meet[i].start > limit) {
      cnt++;
      limit = meet[i].end;
    }
  }

  return cnt;

}