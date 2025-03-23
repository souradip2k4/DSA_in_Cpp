// https://leetcode.com/problems/remove-k-digits/
// 402. Remove K Digits

#include <bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k) {
  stack<char> st;

  for (char ch: num) {
    if (st.empty()) {
      st.push(ch);
    } else {
      while (!st.empty() && k > 0 && (ch) < st.top()) {
        st.pop();
        k--;
      }
      st.push(ch);
    }
  }

  // If k is not 0 and stack not empty we will keep poping
  while (k > 0 && !st.empty()) {
    st.pop();
    k--;
  }

  if (st.empty()) {
    return "0";
  } else {
    string str = "";
    while (!st.empty()) {
      str += st.top();
      st.pop();
    }

    reverse(str.begin(), str.end());
    int i = 0;
    for (char ch: str) {
      // Removes all 0s at the beginning of teh digit
      if (ch == '0') {
        i++;
      } else {
        break;
      }
    }
    str = str.substr(i, str.size() - i);

    if (str.empty()) {
      return "0";
    }
    return str;
  }
}

int main() {
  cout << removeKdigits("1432219", 3) << endl;
  cout << removeKdigits("10200", 1) << endl;
  cout << removeKdigits("10", 2) << endl;
  cout << removeKdigits("10", 1) << endl;
}
