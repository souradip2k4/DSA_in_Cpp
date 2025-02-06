// 5. Longest Palindromic Substring
// https://leetcode.com/problems/longest-palindromic-substring/description/

#include <bits/stdc++.h>
using namespace std;

/*string longestPalindrome(string s) {
  if (s.size() <= 1) {
    return "";
  }

  int maxLen = 2, l = 0, r = 0;
  string str = "", str2="", longest = "";

  while (l < s.size()) {
    r = l + maxLen - 1;
    while (r < s.size()) {
      str = s.substr(l, r - l + 1);
      str2 = str;
      reverse(str2.begin(), str2.end());
      if (str == str2) {
        maxLen = max(maxLen, (int)str.size());
        longest = str;
      }

      r++;
    }

    l++;
  }

  return longest;
}*/

string expandAroundCentre(string s, int l, int r) {
  while (l >= 0 && r < s.size() && s[l] == s[r]) {
    l--;
    r++;
  }

  return s.substr(l + 1, r - l - 1);
}

string longestPalindrome(string s) {
  if (s.size() <= 1) {
    return s;
  };

  string longest = "";
  int maxLen = 0;
  for (int i = 0; i < s.size(); i++) {
    string oddPalindrome = expandAroundCentre(s, i, i);
    if (oddPalindrome.size() > longest.size()) {
      longest = oddPalindrome;
    }

    string evenPalindrome  = expandAroundCentre(s, i , i+1);
    if (evenPalindrome.size() > longest.size()) {
      longest = evenPalindrome;
    }
  }

  return longest;
}

int main() {
  string r1 = longestPalindrome("babad");
  string r2 = longestPalindrome("ac");

  cout << r1 << endl;
}
