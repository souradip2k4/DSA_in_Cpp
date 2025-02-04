// 205
// https://leetcode.com/problems/isomorphic-strings/description/

#include<bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t) {
  if (s.size() != t.size()) {
    return false;
  }

  string str;
  unordered_map<char, char> uMap;

  for (int i = 0; i < s.size(); i++) {
    if (uMap.find(s[i]) == uMap.end()) {
      uMap[s[i]] = t[i];
      str.push_back(t[i]);
    } else {
      str.push_back(uMap[s[i]]);
    }
  }

  cout << str << endl;
  if (t == str) {
    return true;
  }

  return false;
}

int main() {
  bool res1 = isIsomorphic("egg", "add");
  bool res2 = isIsomorphic("paper", "title");
  bool res3 = isIsomorphic("foo", "bar");
  bool res4 = isIsomorphic("badc", "baba");

  cout << res4 << endl;
}
