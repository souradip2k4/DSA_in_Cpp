// 151
// https://leetcode.com/problems/reverse-words-in-a-string/description/

#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
  // Trim leading and trailing spaces
  int start = 0, end = s.size() - 1;
  while (start <= end && s[start] == ' ') start++;
  while (start <= end && s[end] == ' ') end--;

  s = s.substr(start, end - start + 1); // Trimmed string
  reverse(s.begin(), s.end()); // Reverse entire string
  s += ' ';
  string str = "", str2 = "";
  int i = 0;

  while (i < s.size()) {
    if (s[i] != ' ') {
      str += s[i]; // Build a word
    } else if (!str.empty()) {
      reverse(str.begin(), str.end()); // Reverse the word
      str2 += str + ' '; // Append to final result with a space
      str = "";
    }
    i++;
  }

  str2 = str2.substr(0, str2.size() - 1);

  return str2;
}


int main() {
  string s1 = reverseWords("the sky is blue"); // blue is sky the
  // string s2 = reverseWords("  hello world  "); // world hello
  // string s3 = reverseWords("a good   example"); // example good a

  cout << "'" << s1 << "'" << endl;
}
