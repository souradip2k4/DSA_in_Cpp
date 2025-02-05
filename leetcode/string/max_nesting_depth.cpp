// 1614
// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/

#include<bits/stdc++.h>
using namespace std;

int maxDepth(string s) {
  int maxD = 0;
  stack<char> st;

  for (char ch: s) {
    if (ch == '(') {
      st.push(ch);
    }

    if (ch == ')') {
      maxD = max(maxD, static_cast<int>(st.size()));
      st.pop();
    }
  }

  return maxD;
}

int main() {
  int res1 = maxDepth("(1+(2*3)+((8)/4))+1");
  int res2 = maxDepth("(1)+((2))+(((3)))");
  int res3 = maxDepth("()(())((()()))");

  cout << res3 << endl;
}
