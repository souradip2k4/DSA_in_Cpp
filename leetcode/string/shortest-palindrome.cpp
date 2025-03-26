// https://leetcode.com/problems/shortest-palindrome/description/
// 214. Shortest Palindrome

#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(int l, int r, string s) {
  while (l <= r) {
    if (s[l] != s[r]) {
      return false;
    }
    l++;
    r--;
  }

  return true;
}

string shortestPalindrome(string s) {
  int l = 0, r = s.size() - 1;

  // Finding the prefix palindrome string always starting from index 0
  while (r >= l && !checkPalindrome(l, r, s)) {
    r--;
  }

  // Concantenating the rest string after the prefix palindrome in reverse order to the original string
  string str = s.substr(r + 1, s.size() - (r + 1)); // s.substr(r + 1, s.size() - 1 - (r + 1) + 1);
  reverse(str.begin(), str.end());
  str = str + s;

  return str;
}

int main() {
  cout << shortestPalindrome("aacecaaa") << endl;
  cout << shortestPalindrome("abcd") << endl;
  cout << shortestPalindrome("abb") << endl;
  cout << shortestPalindrome("aabba") << endl;
  cout << shortestPalindrome("aaaabbaa") << endl;
}
