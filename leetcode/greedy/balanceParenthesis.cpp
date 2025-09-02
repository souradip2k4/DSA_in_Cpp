#include<bits/stdc++.h>
using namespace std;

bool checkValidString(string s) {
  int low = 0, high = 0;


  for (char ch : s) {
    if (ch == '(') {
      low++;
      high++;
    }

    if (ch == ')') {
      if (low > 0) low--; // ch = '('
      high--;
    }

    if (ch == '*') {
      if (low > 0) low--; // * = ')'
      high++; // * = '('
    }

    if (high < 0) return false; // Too many ')'
  }

  return low == 0;

}