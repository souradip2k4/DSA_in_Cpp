// 205
// https://leetcode.com/problems/isomorphic-strings/description/

#include<bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t) {
  if (s.size() != t.size()) {
    return false;
  }

  string str;
  unordered_map<char, char> uMapS, uMapT;

  for (int i = 0; i < s.size(); i++) {
    char c1 = s[i], c2 = t[i];
    if (uMapS.count(c1) && uMapS[c1] != c2) return false;

    if (uMapT.count(c2) && uMapT[c2] != c1) return false;

    uMapS[c1] = c2;
    uMapT[c2] = c1;
  }

  return true;
}

int main() {
  bool res1 = isIsomorphic("egg", "add");
  bool res2 = isIsomorphic("paper", "title");
  bool res3 = isIsomorphic("foo", "bar");
  bool res4 = isIsomorphic("badc", "baba");

  cout << res2 << endl;
}
