// 796.  Rotate string
// https://leetcode.com/problems/rotate-string/description/

#include <bits/stdc++.h>
using namespace std;

bool rotateString(string s, string goal) {
  if (s.size() != goal.size()) {
    return false;
  }

  for (int i = 0; i < s.size(); i++) {
    reverse(s.begin(), s.end());
    reverse(s.begin() + 1, s.end());

    if (s == goal) {
      return true;
    }
  }

  return false;
}

int main() {
  bool r1 = rotateString("abcde", "cdeab");

  cout << r1 << endl;
}
