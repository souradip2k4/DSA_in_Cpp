// 1021
// https://leetcode.com/problems/remove-outermost-parentheses/

#include <bits/stdc++.h>
using namespace std;

/*string removeOuterParentheses(string s) {
  stack<int> st;
  string str = "";
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(') {
      st.push(s[i]);
    } else {
      st.pop();
    }

    // If st.size() > 1 that means '(' is not outermost parenthesis
    if (s[i] == '(' && st.size() > 1) {
      str += s[i];
    }

    // If st.size() >= 1 that means ')' is not outermost parenthesis
    if (s[i] == ')' && st.size() >= 1) {
      str += s[i];
    }
  }

  return str;
}*/

string removeOuterParentheses(string s) {
  string str = "";
  int balance = 0;

  for (int i = 0; i < s.size(); i++) {

    // If balance > 0 that means '(' is not outermost parenthesis
    if (s[i] == '(') {
      if (balance > 0) {
        // str += s[i];
        str.push_back(s[i]);
      }

      balance++;
    } else {
      // Decreasing balance by 1 for ')'
      balance--;

      //  If balance > 0 that means ')' is not outermost parenthesis
      if (balance > 0) {
        // str += s[i];
        str.push_back(s[i]);
      }
    }
  }

  return str;
}

int main() {
  string s = removeOuterParentheses("(()())(())(()(()))");
  // string s = removeOuterParentheses("(()())(())");

  cout << s << endl;
}
