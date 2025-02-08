// 214. Shortest Palindrome
// https://leetcode.com/problems/shortest-palindrome/description/

#include <bits//stdc++.h>
using namespace std;

string palindrome(string s, int l, int r) {
  while (l >= 0 && r  < s.size() && s[l]==s[r]) {
    l--;
    r++;
  }

}

string shortestPalindrome(string s) {
  string str;
  if (s.size() % 2 == 0) {
    str = palindrome(s, (s.size() / 2) - 1, s.size() / 2);
  } else {
    str = palindrome(s, s.size()/2, s.size()/2);
  }

}

int main() {
  string r1 = shortestPalindrome("aacecaaa");
  string r2 = shortestPalindrome("abcd");

  cout << r1 << endl;
}
