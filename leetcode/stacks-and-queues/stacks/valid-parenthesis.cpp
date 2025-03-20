// https://leetcode.com/problems/valid-parentheses/
// 20. Valid Parentheses


#include<bits/stdc++.h>
using namespace std;

bool isValid(string s) {
  stack<char> st;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
      st.push(s[i]);
    } else {
      if (st.empty()) {
        return false;
      }

      if (!st.empty()) {
        if ((s[i] == ')' && st.top() == '(') ||
            (s[i] == '}' && st.top() == '{') ||
            (s[i] == ']' && st.top() == '[')
        ) {
          st.pop();
        } else {
          return false;
        }
      }
    }
  }

  return st.empty();
}

int main() {
  cout << isValid("()") << endl;       // Output: 1
  cout << isValid("()[]{}") << endl;   // Output: 1
  cout << isValid("(]") << endl;       // Output: 0
  cout << isValid("([)]") << endl;     // Output: 0
  cout << isValid("{[]}") << endl;     // Output: 1
}