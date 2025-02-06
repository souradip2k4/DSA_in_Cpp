// 921. Minimum Add to Make Parentheses Valid
// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/

#include<bits/stdc++.h>
using namespace std;

int minAddToMakeValid(string s) {
  stack<int> st;
  int count = 0, balance = 0;

  for (char ch: s) {
    if (ch == '(') {
      balance++;
    }

    if (ch == ')') {
      if (balance > 0) {
        balance--;
      } else {
        count++;
      }
    }
  }

  while (balance > 0) {
    count++;
    balance--;
  }

  return count;
}

int main() {
  int r1 = minAddToMakeValid("())");
  int r2 = minAddToMakeValid("(((");

  cout << r2<< endl;
}
