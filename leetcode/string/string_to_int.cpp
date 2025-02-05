// 8. String to Integer (atoi)
// https://leetcode.com/problems/string-to-integer-atoi/description/
#include<bits/stdc++.h>
using namespace std;

int myAtoi(string s) {
  int sign = 1, i = 0;
  long long num = 0;
  while (i < s.size() && s[i] == ' ') i++;

  if (s[i] == '-') {
    sign = -1;
    i++;
  } else if (s[i] == '+') {
    i++;
  }

  while (i < s.size()) {
    if (s[i] >= '0' && s[i] <= '9') {
      num = num * 10 + (s[i] - '0');
      if (num > INT_MAX && sign == 1) {
        return INT_MAX;
      } else if (num > INT_MAX && sign == -1) {
        return INT_MIN;
      }
      i++;
    } else {
      return (int) (sign * num);
    }
  }

  return (int) (sign * num);
}

int main() {
  int r1 = myAtoi("42");
  int r2 = myAtoi(" -042");
  int r3 = myAtoi("1337c0d3");
  int r4 = myAtoi("words and 987");
  int r5 = myAtoi("-91283472332");

  cout << r2 << endl;
  // cout << stoi("1337c0d3") << endl;
}
