// 1903
// https://leetcode.com/problems/largest-odd-number-in-string/description/

#include <bits/stdc++.h>
using namespace std;

string largestOddNumber(string number) {
  for (int i = number.size() - 1; i >= 0; i--) {
    if (number[i] - '0' % 2 != 0) {
      return number.substr(0, i + 1);
    }
  }

  return "";
}


int main() {
  string s1 = largestOddNumber("52");
  string s2 = largestOddNumber("4206");
  string s3 = largestOddNumber("35427");
  string s4 = largestOddNumber("35476");

  cout << s3 << endl;
}
