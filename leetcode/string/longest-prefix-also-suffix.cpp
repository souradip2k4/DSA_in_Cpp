#include<bits/stdc++.h>
using namespace std;

bool isIdentical(int l, int r, string s) {
  while (r < s.size()) {
    if (s[l] != s[r]) {
      return false;
    }

    l++;
    r++;
  }

  return true;
}

string longestPrefixAndSuffix(string s) {
  int r = s.size() - 1;

  string str = "", maxStr = "";
  while (0 < r) {
    if (isIdentical(0, r, s)) {
      str = s.substr(r, s.size() - r); //(r, s.size() - 1 - r + 1)
      if (str.size() > maxStr.size()) {
        // Finding to longest common prefix
        maxStr = str;
      }
    }
    r--;
  }

  return maxStr;
}

int main() {
  cout << longestPrefixAndSuffix("aabcdaabc") << endl;
  cout << longestPrefixAndSuffix("ababab") << endl;
  cout << longestPrefixAndSuffix("aaaa") << endl;
}
