// 14
// https://leetcode.com/problems/longest-common-prefix/description/

#include<bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &strs) {
  string prefix = strs[0];

  for (string s: strs) {
    while (s.find(prefix) != 0) {
      prefix = prefix.substr(0, prefix.size() - 1);
    }
  }

  return prefix;
}

int main() {
  vector<string> str1 = {"flower", "flow", "flight"};
  string s1 = longestCommonPrefix(str1);

  cout << s1 << endl;
}
