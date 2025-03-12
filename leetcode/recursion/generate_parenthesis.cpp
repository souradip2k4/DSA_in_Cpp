// 22. Generate Parentheses
// https://leetcode.com/problems/generate-parentheses/description/

#include <bits/stdc++.h>
using namespace std;

void dfs(int firstPos, int lastPos, string s, int n, vector<string> &arr) {
  if (firstPos == lastPos && firstPos + lastPos == 2 * n) {
    arr.push_back(s);
    return;
  }

  if (firstPos < n) {
    dfs(firstPos + 1, lastPos, s + '(', n, arr);
  }

  if (lastPos < firstPos) {
    dfs(firstPos, lastPos + 1, s + ')', n, arr);
  }
}

vector<string> generateParenthesis(int n) {
  vector<string> arr;
  dfs(0, 0, "", n, arr);

  return arr;
}


int main() {
  vector<string> res = generateParenthesis(3);

  for (string &s: res) {
    cout << s << ", ";
  }
}
