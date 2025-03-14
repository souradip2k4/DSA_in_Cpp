// https://leetcode.com/problems/minimum-window-substring/description/
// 76. Minimum Window Substring

#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
  unordered_map<char, int> uMap1, uMap2;
  for (char ch: t) {
    uMap1[ch]++;
    uMap2[ch] = 0;
  }

  int l = 0, r = 0;
  vector<string> arr1;

  while (l <= r && r < s.size()) {
    uMap2[s[r]]++;

    bool b = false;
    for (auto it: uMap1) {
      while (uMap2[it.first] > it.second) {
        uMap2[s[l]]--;
        l++;
      }


      if (uMap2[it.first] == it.second) {
        b = true;
      } else {
        b = false;
      }
    }

    if (b == true) {
      while (uMap1.find(s[l]) == uMap1.end()) {
        uMap2[s[l]]--;
        l++;
      }
      arr1.push_back(s.substr(l, r - l + 1));
    }

    r++;
  }

  string res = arr1[0];
  for (string str: arr1) {
    if (str.size() < res.size()) {
      res = str;
    }
  }

  return res;
}

int main() {
  string res1 = minWindow("ADOBECODEBANC", "abc");
  string res2 = minWindow("a", "a");
  string res3 = minWindow("a", "aa");

  cout << res1 << endl;
}
