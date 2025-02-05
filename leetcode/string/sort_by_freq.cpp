// 451. Sort Characters By Frequency
// https://leetcode.com/problems/sort-characters-by-frequency/description/

#include <bits/stdc++.h>
using namespace std;

string frequencySort(string s) {
  unordered_map<char, int> uMap;
  vector<pair<char, int> > v;
  string str = "";

  for (char ch: s) {
    uMap[ch]++;
  }

  v = {uMap.begin(), uMap.end()};
  sort(v.begin(), v.end(), [](const pair<char, int> &a, const pair<char, int> &b) {
    return a.second > b.second;
  });

  for (auto it: v) {
    while (it.second > 0) {
      str += it.first;
      it.second--;
    }
  }

  return str;
}

int main() {
  string res1 = frequencySort("tree");

  cout << res1 << endl;
}
