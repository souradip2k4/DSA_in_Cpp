// 242. Valid Anagram
// https://leetcode.com/problems/valid-anagram/

#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
  if (s.size() != t.size()) {
    return false;
  }
  int hash[26] = {0};

  for (char ch: s) {
    hash[ch - 'a']++;
  }

  for (char ch: t) {
    if (hash[ch - 'a'] == 0) return false;

    hash[ch - 'a']--;
  }

  for (int num: hash) {
    if (num != 0) return false;
  }
  return true;
}


int main() {
  bool r1 = isAnagram("anagram", "nagaram");
  bool r2 = isAnagram("rat", "car");
  bool r3 = isAnagram("aacc", "ccac");

  cout << r3 << endl;
}
